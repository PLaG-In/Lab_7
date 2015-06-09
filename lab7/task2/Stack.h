#pragma once

template <typename T>
class CStack
{
public:

	struct Item
	{
		// ����������� �������� ���������, ��� ���������� �.�. perfect forwarding
		// � ������, ����� ���������� �������� rvalue, �������� ����� ����������
		// � ��������� ������ - �����������
		template <typename TT>
		Item(TT && value, std::unique_ptr<Item> && previous)
			: value(std::forward<T>(value))
			, previous(std::move(previous))
		{}

		T value;
		std::unique_ptr<Item> previous;
	};

	bool IsEmpty() const
	{
		return !m_top;
	}

	// ����� Push �������� ���������, ��� ���������� �.�. perfect forwarding
	// � ������, ����� ���������� �������� rvalue, �������� ����� ����������
	// � ��������� ������ - �����������
	template <typename TT>
	void Push(TT && value)
	{
		m_top = std::make_unique<Item>(std::forward<T>(value), move(m_top));
	}

	T Peek()
	{
		return m_top->value;
	}

	T Pop()
	{
		T top = m_top->value;
		m_top = std::move(m_top->previous);
		return top;
	}


private:
	std::unique_ptr<Item> m_top;
};

