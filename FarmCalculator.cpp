#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int totalAcres = 0,				//Total farm size in acres
		numPlanted = 0;				//Number of vegetables to be planted

	double
		landUsed = 0.00,			//Portion of land used
		landUsedPerc = 0.00,		//Percentage of land used for first vegetable
		landUsedTwoPerc = 0.00;		//Percentage of land used for second vegetable

	double	
		scpAcre = 0.00,				//Seed cost per acre
		pcpAcre = 0.00,				//Plantation cost per acre
		fcpAcre = 0.00,				//Fetilizing cost per acre
		lcpAcre = 0.00,				//Labor cost per acre
		vcpAcre = 0.00;				//Vegetable selling cost per acre

	double 
		scpAcreTwo = 0.00,			//Seed cost per acre for second vegetable
		pcpAcreTwo = 0.00,			//Plantation cost per acre second vegetable
		fcpAcreTwo = 0.00,			//Fertilizing cost per acre for second vegetable
		lcpAcreTwo = 0.00,			//Labor cost per acre for second vegetable
		vcpAcreTwo = 0.00;			//Vegetable selling cost per acre for second vegetable

	double 
		totalRev = 0.00,			//Total revenure from farm
		totalExpOne = 0.00,			//Total expenses for first vegetable
		totalExpTwo = 0.00,			//Total expenses for second vegetable
		totalProfitLoss = 0.00;		//Total proft/loss from farm

	char q;

	cout << "Anthony Cantu\t" << "L2-2\t" << "L2-2.exe" << endl << endl;

	while (cin)
	{
		cout << "Enter farm area in acres: ";
		cin >> totalAcres;
		cout << endl; //Line Break
		if (!cin) break;

		cout << "Enter the number of vegetables planted (1/2): ";
		cin >> numPlanted;
		cout << endl; //Line Break
		if (!cin) break;
		if (numPlanted < 1 || numPlanted > 2) //Invalid entry check
		{
			cout << endl << "Please enter a value of 1 or 2" << endl << endl
				<< "Press enter to Exit.";

			cin.ignore(2, '\n');
			cin.get(q);

			return 1;
		}

		if (numPlanted == 1)
		{
			cout << "Enter seed cost per acre: $";
			cin >> scpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter plantation cost per acre: $";
			cin >> pcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter fetilizing cost per acre: $";
			cin >> fcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter labor cost per acre: $";
			cin >> lcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter vegetable selling cost per acre: $";
			cin >> vcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			break;
		}
		else if (numPlanted == 2)
		{
			cout << "Enter the portion (as a percentage) of land used "
				<< "for the first vegetable: ";
			cin >> landUsed;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter first vegetable seed cost per acre: $";
			cin >> scpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter first vegetable plantation cost per acre: $";
			cin >> pcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter first vegetable fertilizing cost per acre: $";
			cin >> fcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter first vegetable labor cost per acre: $";
			cin >> lcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter first vegetable selling cost per acre: $";
			cin >> vcpAcre;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter second vegetable seed cost per acre: $";
			cin >> scpAcreTwo;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter second vegetable plantation cost per acre: $";
			cin >> pcpAcreTwo;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter second vegetable fertilizing cost per acre: $";
			cin >> fcpAcreTwo;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter second vegetable labor cost per acre: $";
			cin >> lcpAcreTwo;
			cout << endl; //Line Break
			if (!cin) break;

			cout << "Enter second vegetable selling cost per acre: $";
			cin >> vcpAcreTwo;
			cout << endl; //Line Break
			if (!cin) break;

			break;
		}
	}

	if (!cin) //Invalid entry check
	{
		cout << endl << "Please enter a number value." << endl << endl
			<< "Press enter to Exit.";

		cin.ignore(2, '\n');
		cin.get(q);

		return 1;
	}

	if (numPlanted == 2)
	{
		//Math for first vegetable
		landUsedPerc = (landUsed / 100) * totalAcres;
		scpAcre *= landUsedPerc;
		pcpAcre *= landUsedPerc;
		fcpAcre *= landUsedPerc;
		lcpAcre *= landUsedPerc;
		vcpAcre *= landUsedPerc;

		//Math for second vegetable
		landUsedTwoPerc = (100 - landUsed) / 100 * totalAcres;
		scpAcreTwo *= landUsedTwoPerc;
		pcpAcreTwo *= landUsedTwoPerc;
		fcpAcreTwo *= landUsedTwoPerc;
		lcpAcreTwo *= landUsedTwoPerc;
		vcpAcreTwo *= landUsedTwoPerc;

		//Add everything up
		totalExpOne = scpAcre + pcpAcre + fcpAcre + lcpAcre;
		totalExpTwo = scpAcreTwo + pcpAcreTwo + fcpAcreTwo + lcpAcreTwo;

		//Find total revenue and total profit/loss
		totalRev = vcpAcre + vcpAcreTwo;
		totalProfitLoss = totalRev - (totalExpOne + totalExpTwo);
	}
	else if (numPlanted == 1)
	{
		//Math for vegetables
		scpAcre *= totalAcres;
		pcpAcre	*= totalAcres;
		fcpAcre *= totalAcres;
		lcpAcre *= totalAcres;

		//Add everything up
		totalExpOne = scpAcre + pcpAcre + fcpAcre + lcpAcre;

		//Find total revenue and total profit/loss
		totalRev = vcpAcre * totalAcres;
		totalProfitLoss = totalRev - totalExpOne;
	}

	cout << fixed << showpoint << setprecision(2);
	cout << "The total revenue is: " << totalRev << endl;
	cout << "Proft/loss from farming: $" << totalProfitLoss << endl;

	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}
