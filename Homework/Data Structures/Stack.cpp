#include <iostream>
#include <memory>

template <typename T, typename... Us>
class Stack
{
private:
	std::unique_ptr<T[]> _ptr;
	int64_t _index;
	size_t _size;

public:
	explicit Stack(const size_t size = 0)
		: _ptr(std::make_unique<T[]>(_size))
		, _index(0)
		, _size(size)
	{
		std::cout << "Stack created\n";
	}

	// initializer list constructor
	explicit Stack(std::initializer_list<T> values)
		: _ptr(std::make_unique<T[]>(values.size()))
		, _index(-1)
		, _size(values.size())
	{
		for (auto el : values)
			_ptr[++_index] = el;
		std::cout << "Stack created through the initializer list\n";
	}

	// variadic constructor
	template <typename... Us>
	explicit Stack(Us... args)
		: _ptr(std::make_unique<T[]>(sizeof...(args)))
		, _index(-1)
		, _size(sizeof...(args))
	{
		((void) ::new (static_cast<void*>(std::addressof(_ptr[++_index]))) T(std::forward<Us>(args)), ...);
		std::cout << "Stack created through the variadic constructor\n";
	}

	~Stack()
	{
		std::cout << "Stack destroyed\n";
	}

	int push(const T& element)
	{
		if (_index + 1 >= _size)
		{
			std::cout << "Error: stack is full\n";
			return 0;
		}
		else
		{
			*(_ptr.get() + _index++ + 1) = element;
			return 1;
		}
	}

	T pop()
	{
		if (_index >= 0)
			return _ptr[_index--];
		else
			std::cout << "Error: stack is empty\n";
	}

	T top() const
	{
		if (_index > -1)
			return _ptr[_index];
	}

	size_t size() const
	{
		return _size;
	}

	int64_t top_index() const
	{
		return _index;
	}

	bool full() const
	{
		return _index + 1 >= _size;
	}

	bool empty() const
	{
		return _index == -1;
	}

	void clear()
	{
		_index = -1;
	}
};

int main()
{
	{
		Stack<int> stack{ 1, 4, 3, 6 };
		std::cout << stack.size() << '\n' << stack.top_index() << '\n';

		while (stack.top_index() >= 0)
			std::cout << stack.pop() << '\n';
	}
	{
		Stack<int> stack( 7, 4, 3, 6 );
		std::cout << stack.size() << '\n' << stack.top_index() << '\n';
		
		
		while (stack.top_index() >= 0)
			std::cout << stack.pop() << '\n';
		int i = 0;
		while (!stack.full())
			stack.push(i++);
		while (stack.top_index() >= 0)
			std::cout << stack.pop() << '\n';
	}

	// question about const in the parameter list of var and init constructors
	// also, copy/move/assign constructors are impossible
}