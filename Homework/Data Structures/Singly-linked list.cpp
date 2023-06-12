#include <iostream>
#include <memory>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt-Algs-and-DS\Homework\Data Structures\ListNode.cpp"

template <typename T>
class SLL
{
private:
    ListNode<T>* head = nullptr;

public:
    SLL(const ListNode<T>* element = nullptr)
    {
        if (element)
            this->head = new ListNode<T>(element->val, nullptr);
    }

    SLL(std::initializer_list<T> values)
        : head(nullptr)
    {
        for (const T& val : values)
        {
            insert(val);
        }
    }

    SLL(const SLL& other)
        : head(nullptr)
    {
        if (other.head)
        {
            head = new ListNode<T>(other.head->val, nullptr);
            ListNode<T>* current = this->head;
            ListNode<T>* otherCurrent = other.head->next;

            while (otherCurrent)
            {
                current->next = new ListNode<T>(otherCurrent->val);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
        std::cout << "copy constructed\n";
    }

    SLL(SLL&& other) noexcept
        : head(other.head)
    {
        other.head = nullptr;
        std::cout << "move constructed\n";
    }

    ~SLL()
    {
        ListNode<T>* current = this->head;
        while (current)
        {
            ListNode<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }


    std::pair<SLL<T>, SLL<T>> split_in_half() const
    {
        ListNode<T>* slow = head, * fast = head;
        SLL<T> first, second;

        while (fast && fast->next)
        {
            first.insert(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast)
        {
            first.insert(slow->val);
            slow = slow->next;
            fast = fast->next;
        }

        while (slow && slow != fast)
        {
            second.insert(slow->val);
            slow = slow->next;
        }

        return std::make_pair(first, second);
    }

    ListNode<T>* reverse()
    {
        ListNode<T>* cur = this->head;
        ListNode<T>* prev = nullptr;
        ListNode<T>* next = nullptr;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        this->head = prev;
        return this->head;
    }

    ListNode<T>* push_front(const T val)
    {
        ListNode<T>* newHead = new ListNode(val, this->head);
        this->head = newHead;
        return head;
    }

    ListNode<T>* get() const
    {
        return this->head;
    }

    void print() const
    {
        ListNode<T>* tmp = this->head;
        while (tmp)
        {
            std::cout << tmp->val << ' ';
            tmp = tmp->next;
        }
    }

    ListNode<T>* insert(T val)
    {
        if (!head) {
            head = new ListNode<T>(val, nullptr);
            return head;
        }

        ListNode<T>* traverse = head;
        while (traverse->next)
            traverse = traverse->next;

        traverse->next = new ListNode<T>(val, nullptr);
        return traverse->next;
    }

    ListNode<T>* insert(ListNode<T>* newNode = nullptr)
    {
        ListNode<T> dummy(0, head);
        ListNode<T>* traverse = &dummy;
        while (traverse->next)
            traverse = traverse->next;
        if (traverse->next == head)
            head = (newNode ? new ListNode<T>(newNode->val, nullptr) : new ListNode<T>(0, nullptr));
        else
            traverse->next = (newNode ? new ListNode<T>(newNode->val, nullptr) : new ListNode<T>(0, nullptr));
        return traverse->next;
    }

    SLL& operator=(const SLL& other)
    {
        if (this == &other)  // Self-assignment check
            return *this;

        // Copy as much of other as fits into current
        ListNode<T>* current = head;
        ListNode<T>* otherCurrent = other.head;
        while (current and otherCurrent)
        {
            current->val = otherCurrent->val;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        // If other is longer than this
        if (otherCurrent)
        {
            while (otherCurrent)
            {
                current = new ListNode(otherCurrent->val, nullptr);
                current = current->next;
            }
        } // if this is longer than other
        else if (current)
        {
            ListNode<T>* tmp;
            while (current)
            {
                tmp = current->next;
                delete current;
                current = tmp;
            }
        }

        return *this;
    }

    void insertionSort()
    {
        ListNode<T>* cur, * prev, * tmp;
        ListNode<T> dummy(0, head);
        cur = head;
        prev = &dummy;
        tmp = nullptr;

        while (cur)
        {
            if (cur->next and cur->next->val < cur->val)
            {
                while (prev->next and prev->next->val < cur->next->val)
                    prev = prev->next;

                tmp = prev->next;
                if (prev->next == head)
                    head = cur->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = tmp;
                prev = &dummy;
                this->print();
            }
            else
                cur = cur->next;
            std::cout << '\n';
        }
    }

    ListNode<T>* midpoint(ListNode<T>* first) const
    {
        ListNode<T>* slow = first, * fast = first->next;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode<T>* merge(ListNode<T>* left, ListNode<T>* right)
    {
        ListNode<T> dummy(0, nullptr);
        ListNode<T>* tail = &dummy;

        while (left and right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (right)
        {
            tail->next = right;
        }
        if (left)
        {
            tail->next = left;
        }
        return dummy.next;
    }

    ListNode<T>* mergeSortHelper(ListNode<T>* start)
    {
        if (!start or !start->next)
            return start;

        auto mid = midpoint(start);
        ListNode<T>* second = mid->next;
        mid->next = nullptr;

        ListNode<T>* left = mergeSortHelper(start);
        ListNode<T>* right = mergeSortHelper(second);

        return merge(left, right);
    }

    void mergeSort()
    {
        this->head = mergeSortHelper(this->head);
    }
};

int main()
{
    SLL<int> shorter;
    SLL<int> longer;
    SLL<int> head;

    for (int i = 9, j = 7, k = 5; i >= 0; i--, j--, k--)
    {
        if (k >= 0)
            shorter.insert(k);
        if (j >= 0)
            head.insert(j);
        if (i >= 0)
            longer.insert(i);
    }
    std::cout << "shorter: \n";
    shorter.print();
    std::cout << '\n';
    std::cout << "head: \n";
    head.print();
    std::cout << '\n';
    std::cout << "longer: \n";
    longer.print();

    std::cout << '\n';

    auto halves = longer.split_in_half();
    halves.first.print();
    std::cout << '\n';
    halves.second.print();
    std::cout << '\n';

    longer.insertionSort();
    std::cout << '\n';
    longer.print();
    std::cout << '\n';

    SLL<int> newSLL{6, 4, 0, 7, 12, 1, 0, 7};
    newSLL.print();
    std::cout << '\n';
    //newSLL.insertionSort();
    newSLL.mergeSort();
    newSLL.print();


}