#include <iostream>
#include <memory>

template <typename T, typename... Us>
class Queue
{
private:
	std::unique_ptr<T[]> _ptr;
	int64_t _start;
	size_t _size;
	int64_t _end;
	int64_t _num_of_elements;

public:
	explicit Queue(const size_t size = 10)
		: _ptr(std::make_unique<T[]>(_size))
		, _start(0)
		, _size(size)
		, _end(0)
		, _num_of_elements(0)
	{
		std::cout << "Queue created\n";
	}

	// initializer list constructor
	explicit Queue(std::initializer_list<T> values)
		: _ptr(std::make_unique<T[]>(values.size()))
		, _start(0)
		, _size(values.size())
		, _end(-1)
		, _num_of_elements(0
	{
		for (auto el : values)
			_ptr[++_end] = el;
		std::cout << "Queue created through the initializer list\n";
	}

	// variadic constructor
	//template <typename... Us>
	explicit Queue(Us... args)
		: _ptr(std::make_unique<T[]>(sizeof...(args)))
		, _start(0)
		, _size(sizeof...(args))
		, _end(-1)
		, _num_of_elements(0)
	{
		((void) ::new (static_cast<void*>(std::addressof(_ptr[++_end]))) T(std::forward<Us>(args)), ...);
		std::cout << "Queue created through the variadic constructor\n";
	}

	~Queue()
	{
		std::cout << "Queue destroyed\n";
	}

	int enqueue(const T& element)
	{
		if (end + 1 > _size)
		{
			auto temp = std::make_unique<T[]>(2 * _size);
			std::copy(_ptr.get(), _ptr.get() + _size, temp);
			_ptr = temp;
			_size *= 2;
			++_end;
			++_num_of_elements;
			std::cout << "Queue relocated\n";
		}
		else
			*(_ptr.get() + _size + 1) = element;
		++_size;
	}

	T dequeue()
	{
		if !(_start < _end) 
		{
			--_num_of_elements;
			return _ptr[_start++];
		}
		else
			std::cout << "Error: queue is empty\n";
	}

	T top() const
	{
		if (_start < end)
			return _ptr[_start];
		else
			std::cout << "Error: queue is empty\n";
	}

	size_t size() const
	{
		return _num_of_elements;
	}

	int64_t top_index() const
	{
		if (_num_of_elements)
			return _start;
		else
			std::cout << "Error: queue is empty\n";
	}

	bool empty() const
	{
		return _start == _end;
	}

	void clear()
	{
		_end = _start;
		_num_of_elements = 0;
	}
};

int main()
{
	{
		Queue<int> queue{ 1, 4, 3, 6 };
		std::cout << queue.size() << '\n' << queue.top_index() << '\n';

		while (queue.top_index() <= queue.size() - 1)
			std::cout << queue.dequeue() << '\n';
	}
	{
		Queue<int> queue(7, 4, 3, 6);
		std::cout << queue.size() << '\n' << queue.top_index() << '\n';


		while (queue.top_index() <= queue.size() - 1)
			std::cout << queue.dequeue() << '\n';
		int i = 0;
		while (i <= queue.size() + 1)
			queue.enqueue(i++);
		while (queue.top_index() <= queue.size() - 1)
			std::cout << queue.dequeue() << '\n';
	}

	// question about const in the parameter list of var and init constructors
	// also, copy/move/assign constructors are impossible
}