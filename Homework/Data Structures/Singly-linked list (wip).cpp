#include <iostream>
#include <memory>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\ListNode.cpp"

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

    ListNode<T>* midpoint(ListNode<T>* first, ListNode<T>* last) const
    {
        ListNode<T>* slow = first, * fast = first;
        while (fast && fast != last && fast->next != last) // WIP!!!!!!!!!
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void merge(ListNode<T>* left, ListNode<T>* mid, ListNode<T>* right)
    {
        SLL<T> L, R;
        ListNode<T>* start = left, * middle = mid, * end = right;
        while (start != middle)
        {
            L.insert(start);
            start = start->next;
        }
        L.insert(middle);
        while (middle != end)
        {
            R.insert(middle);
            middle = middle->next;
        }
        R.insert(middle);

        ListNode<T>* tmp = nullptr;
        start = L.get();
        end = R.get();
        
        while (start && end && left)
        {
            tmp = left->next;
            delete left;
            left = (start->val < end->val ? new ListNode<T>(start->val, tmp) : new ListNode<T>(start->val, tmp));
            left = left->next;
        }
        while (start && left)
        {
            tmp = left->next;
            delete left;
            left = new ListNode<T>(start->val, tmp);
            start = start->next;
        }
        while (end && left)
        {
            tmp = left->next;
            delete left;
            left = new ListNode<T>(end->val, tmp);
            end = end->next;
        }
    }

    void mergeSortHelper(ListNode<T>* left, ListNode<T>* right)
    {
        if (left != right)
        {
            auto mid = midpoint(left, right);

            mergeSortHelper(left, mid);
            mergeSortHelper(mid->next, right);

            merge(left, mid, right);
        }
    }

    void mergeSort()
    {
        ListNode<T>* right = head;

        while (right && right->next)
            right = right->next;

        mergeSortHelper(head, right);
    }
};

int main()
{
    /*SLL<int> shorter;
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
    std::cout << '\n';*/

    SLL<int> newSLL{6, 4, 0, 7, 12, 1, 0, 7};
    //newSLL.insertionSort();
    newSLL.mergeSort();
    newSLL.print();
       

}