string removeStars(string s) 
{ // use a new string
	std::stack<char> stack;

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (*it == '*')
		{
			stack.pop();
			continue;
		}
		stack.push(*it);
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