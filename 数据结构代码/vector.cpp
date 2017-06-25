#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Vector {
   private:
		int size, length;
	    Type* data;
    public:
		Vector(int input_size)
		{
			size = input_size;
			length = 0;
			data = new Type[size];
		}
		~Vector()
		{
			delete[] data;
		}
		void insert(int loc, Type value)
		{
			if (loc < 0 || loc > length )
			{
				cout << "failed" << endl;
				return;
			}
			if (length >= size)
			{
				cout << "expand" << endl;
				expand();
			}
			for (int i = length; i > loc; --i) {
				data[i] = data[i - 1];
			}
			data[loc] = value;
			length++;
			cout << "success" << endl;
			return;
			
		}
		void expand()
		{
			Type* old_data = data;
			size = size * 2;
			data = new Type[size];
			for (int i = 0; i < length; i++)
			{
				data[i] = old_data[i];
			}
			delete[] old_data;
		}
};

int main()
{
	Vector < int> a(5);
	int num;
	cin >> num;
	int x, y;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		a.insert(x, y);
	}
	system("pause");
	return 1;
}