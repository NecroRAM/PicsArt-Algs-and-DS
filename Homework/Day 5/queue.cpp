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
	explicit Queue(const size_t size = 0)
		: _ptr(std::make_unique<T[]>(_size))
		, _start(0)
		, _size(size)
		, _end(0)
	{
		std::cout << "Queue created\n";
	}

	// initializer list constructor
	explicit Queue(std::initializer_list<T> values)
		: _ptr(std::make_unique<T[]>(values.size()))
		, _start(0)
		, _size(values.size())
		, _end(-1)
	{
		for (auto el : values)
			_ptr[++_end] = el;
		std::cout << "Queue created through the initializer list\n";
	}

	// variadic constructor
	template <typename... Us>
	explicit Queue(Us... args)
		: _ptr(std::make_unique<T[]>(sizeof...(args)))
		, _start(0)
		, _size(sizeof...(args))
		, _end(-1)
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
		if (_end + 1 >= _size)
		{
			if (_start == 0)
			{
				std::cout << "Error: queue is full\n";
				return 0;
			}
			else
			{
				_end = _ptr.get();
				_ptr[end] = element;
				++_num_of_elements;
				return 1;
			}
		}
		else if (_end + 1 != _start)
		{
			*(_ptr.get() + _end++ + 1) = element;
			++_num_of_elements;
			return 1;
		}
	}
	// WIP v
	T dequeue()
	{
		if !(_start > 0)
			return _ptr[_start++];
		else
			std::cout << "Error: queue is empty\n";
	}

	T top() const
	{
		if (_start > -1)
			return _ptr[_start];
	}

	size_t size() const
	{
		return _size;
	}

	int64_t top_index() const
	{
		return _start;
	}

	bool full() const
	{
		return _start + 1 >= _size;
	}

	bool empty() const
	{
		return _start == -1;
	}

	void clear()
	{
		_start = -1;
	}
};

int main()
{
	{
		Queue<int> queue{ 1, 4, 3, 6 };
		std::cout << queue.size() << '\n' << queue.top_index() << '\n';

		while (queue.top_index() >= 0)
			std::cout << queue.dequeue() << '\n';
	}
	{
		Queue<int> queue(7, 4, 3, 6);
		std::cout << queue.size() << '\n' << queue.top_index() << '\n';


		while (queue.top_index() >= 0)
			std::cout << queue.dequeue() << '\n';
		int i = 0;
		while (!queue.full())
			queue.enqueue(i++);
		while (queue.top_index() >= 0)
			std::cout << queue.dequeue() << '\n';
	}

	// question about const in the parameter list of var and init constructors
	// also, copy/move/assign constructors are impossible
}