#include <iostream>
#include "football.h"
using namespace std;

int main()
{
	size_t n;
	Player* arr = createTeam("data.txt", n);
	printTeam(arr, n);
	cout << "Test 1" << "\n";
	try {
		arr[0].addGoals(-9);
	}
	catch (const char* err)
	{
		cout << "Error!" << err << "\n";
	}

	cout << "Test 2" << "\n";
	try
	{
		arr[1].addGoals(-0.3);
	}
	catch(const Player::GoalException& E)
	{
	cout << "Some error" <<"\n";
	E.info();
	}
	Club arsenal("Arsenal", 80);
	Club zenit("Zenit", 200);
	for (size_t i = 0; i < n; ++i)
	{
		cout << "Selling player\n";
		arr[i].print();

		bool sold = false;
		try
		{
			arr[i].setClub(zenit);
			sold = true;
		}
		catch (const Player::ClubNameException& E)
		{
			E.info();
		}

		if (!sold)
		{
			try
			{
				arr[i].setClub(arsenal);
				sold = true;
			}
			catch (const Player::ClubRateException& E)
			{
				E.info();
			}
		}

		if (sold)
		{
			cout << "Sold done!\n";
		}
		else
		{
			cout << "Sold not done!\n";
		}
		cout << endl;
	}
	delete[] arr;
	system("pause");
	return 0;
}