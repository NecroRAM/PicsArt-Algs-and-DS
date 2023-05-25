string removeStars(string s) 
{
	std::stack<char> stack;

	for (char c : s)
	{
		if (c == '*')
			stack.pop();
		else
			stack.push(c);
	}
	s.clear();
	while (stack.size())
	{
		s.push_back(stack.top());
		stack.pop();
	}
	std::reverse(s.begin(), s.end());
	return s;
}