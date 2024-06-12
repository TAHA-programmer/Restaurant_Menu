#include<iostream>
#include<string>
using namespace std;
struct rest_menu
{
	string name, contact;
	string items[20] = { "biryani","pulao","naan","rooti","pizza","burger","fries","golgapay","sandwitch","fried_egg","soop","biscuits","pasta","noodles","cake","salad","raita","juice","chat","drink" };
	int prices[20] = { 170,350,20,15,900,400,100,100,80,40,150,100,200,150,800,100,100,90,150,150 };
	string dishes[6];
	float quantity[6];
	float t_quantity = 0;
	float dish_total[6];
	float total = 0;
	float t_total = 0;
	float gst;
};
void printmenu(rest_menu& vr)
{
	cout << "Items\t\t\tPrices" << endl;
	for (int i = 0; i < 20; i++)
		cout << vr.items[i] << "\t\t\t" << vr.prices[i] << endl;
}
int menu(rest_menu& vr, int s)
{
	int i;
	char ch;
	cout << "Enter your name:";
	cin >> vr.name;
	cout << "Enter your contact number:";
	cin >> vr.contact;
	for (i = 0; i < s; i++)
	{
		cout << "Enter your order:";
		cin >> vr.dishes[i];
		cout << "Enter quantity of " << vr.dishes[i] << ":";
		cin >> vr.quantity[i];
		for (int j = 0; j < i; j++)
		{
			if (vr.dishes[i] == vr.dishes[j])
			{
				vr.quantity[j] = vr.quantity[j] + vr.quantity[i];
				i--;
			}
		}
		cout << "Do you want to order more?...(Enter y for yes):";
		cin >> ch;
		if (ch != 'y')
		{
			cout << "Thanks!" << endl;
			break;
		}
	}
	if (ch == 'y')
	{
		cout << "Sorry!Your limit of having 6 dishes have been reached,You cant buy more:" << endl;
		i--;
	}
	return i+1;
}
void calc(rest_menu& vr, int s)
{
	int i, j;
	for (j = 0; j < s; j++)
	{
		for (i = 0; i < 20; i++)
		{
			if (vr.dishes[j] == vr.items[i])
				vr.dish_total[j] = vr.quantity[j] * vr.prices[i];
		}
		vr.t_quantity = vr.t_quantity + vr.quantity[j];
	}
	for (i = 0; i < s; i++)
	{
		vr.total = vr.total + vr.dish_total[i];
		vr.gst = (12 * vr.total) / 100;
	}
	vr.t_total = vr.total + vr.gst;
}
void showbill(rest_menu& vr,int s)
{
	int i;
	cout << "|--------------------------------------------------|" << endl;
	cout << "|Name                    Qty                  Total|" << endl;
	for (i = 0; i < s; i++)
	{
		cout << "|"<<vr.dishes[i] << "\t\t\t " << vr.quantity[i] << "\t\t\t" << vr.dish_total[i]<<"|" << endl;
	}
	cout << "|       TotalQty  " << vr.t_quantity <<"\t\t\t\t   |"<< endl;
	cout << "|       TotalAmount  " << vr.total << "\t\t\t   |"<<endl;
	cout << "|       GST   " << vr.gst << "\t\t\t\t   |"<<endl;
	cout << "|       Total   " << vr.t_total << "\t\t\t\t   |" << endl;
	cout << "----------------------------------------";
}
int main()
{
	rest_menu var;
	int n = 6;
	printmenu(var);
	n = menu(var, n);
	calc(var, n);
	showbill(var, n);
	return 0;
}