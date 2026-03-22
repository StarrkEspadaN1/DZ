//ps Я забыл код собственного магаза в гит закинуть и пришлось чей-то брать и менять название и товары

#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>

// ----------------------Ó÷åòíûå çàïèñè------------------
size_t userSize = 3;
size_t staffCount = 1;//ñäåëàòü ïðîâåêðè
std::string userStatus[3]{ "Ñóïåð àäìèíèñòðàòîð","Àäìèíèñòðàòîð","Ñîòðóäíèê" };
std::string* loginArr = new std::string[userSize]{ "admin","admin123","user" };
std::string* passArr = new std::string[userSize]{ "admin","admin123","user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0],userStatus[1],userStatus[2] };
double* bonusArr = new double[userSize] {0.0, 0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3};
unsigned int currentId = 0;
std::string currentStatus;




void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUsers();
void ChangePass();
void DeleteUser();

//-------------------------------------------------------

//---------------------Ñêëàä-----------------------------
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* counterArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreate = false;

void createStorage();
void ShowStorage(int mode = 0);

void zeroCreateStorage();

void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();

void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();


template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);
//-------------------------------------------------------

//---------------------Ïðîäàæè---------------------------

size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cashIncome = 0.0;
double bankIncome = 0.0;
double cash = 6000 + rand() % 7500;

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageReturner();
//---------------------------Ñêèäêè----------------------


double discounts(double& totalSum);
double birthdayDiscount(double& totalSum);




//--------------------Ñëóæåáíûå ôóíêöèè------------------
std::unordered_set<char> loginSymbols;
bool isLoginSetCreated = false;
std::unordered_set<char> passSymbols;
bool isPassSetCreated = false;

void Start();
bool login();
bool logout();
void SetLoginSymbols();
void SetPassSymbols();
void ShowIncome();
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
inline void Err(int time = 1500);

//-------------------------------------------------------



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	Start();
	delete[] loginArr;
	delete[]passArr;
	delete[]statusArr;
	if (isStorageCreate)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]counterArr;
		delete[]priceArr;
		delete[]bonusArr;
		delete[]userIdArr;
	}


	return 0;
}

//------------------------------------------------------------------------

void ChangeUsers()
{
	if (isLoginSetCreated == false)
	{
		SetLoginSymbols();
	}
	if (isPassSetCreated == false)
	{
		SetPassSymbols();
	}

	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Äîáàâèòü íîâîãî ïîëüçîâàòåëÿ\n";
		std::cout << "2 - Ïîêàçàòü ïîëüçîâàòåëåé\n";
		std::cout << "3 - Èçìåíèòü ïàðîëü ïîëüçîâàòåëÿ\n";
		std::cout << "4 - Óäàëèòü ïîëüçîâàòåëÿ\n";
		std::cout << "0 - Âûõîä èç ðåäàêòîðà\n";
		std::cout << "Ââîä - ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			AddNewUsers();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize < 2)
			{
				std::cout << "Ïîëüçîâàòåëè îòñóòñòâóþò!\n";
			}
			Err();
		}
	}

}
void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::cout << "¹\t" << std::left << std::setw(12) << "Ëîãèí\t\t " << "   Ïàðîëü\t\t\t" << "Ðîëü\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		std::cout << "¹\t" << std::left << std::setw(12) << "Ëîãèí\t\t " << "   Ïàðîëü\t\t\t" << "Ðîëü\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t"
				<< statusArr[i] << "\n";
		}
	}
	system("pause");


}

void AddNewUsers()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "Ââåäèòå ëîãèí íîâîãî ïîëüçîâàòåëÿèëè exit äëÿ âûõîäà ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Îòìåíà äîáàâëåíèå íîâîãî ïîëüçîâàòåëÿ";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Äîïóñòèìûå ñèâîëû a-z, A-Z, 0-9\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Ââåäèòå ïàðîëü íîâîãî ïîëüçîâàòåëÿèëè exit äëÿ âûõîäà ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Îòìåíà äîáàâëåíèå íîâîãî ïîëüçîâàòåëÿ";
				exit = false;
				Sleep(1500);
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Äîïóñòèìûå ñèâîëû a-z, A-Z, 0-9 + ñïåö ñèìâîëû\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Âûáåðèòå ðîëü íîâîãî ïîëüçîâàòåëÿèëè exit äëÿ âûõîäà";
			std::cout << "1 - Àäìèí\n 2 - Ñîòðóäíèê\nÂâîä: ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "Îòìåíà äîáàâëåíèå íîâîãî ïîëüçîâàòåëÿ";
				exit = false;
				Sleep(1500);
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}

		while (exit)
		{
			std::cout << "Ïîëüçîâàòåëü - " << newLogin << "\n";
			std::cout << "Ïàðîëü - " << newPass << "\n";
			std::cout << "Ðîëü - " << newRole << "\n";
			std::cout << "Ïîäòâåðäèòü? \n 1 - äà\n2 - íåò\nÂâîä - ";
			Getline(choose);
			if (choose == "1")
			{
				userSize++;
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				double* bonusArrTemp = new double[userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];



				FillArray(loginArrTemp, loginArr, userSize - 1);
				FillArray(passArrTemp, passArr, userSize - 1);
				FillArray(statusArrTemp, statusArr, userSize - 1);
				FillArray(bonusArrTemp, bonusArr, userSize - 1);
				FillArray(userIdArrTemp, userIdArr, userSize - 1);


				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				bonusArrTemp[userSize - 1] = 0.0;
				userIdArrTemp[userSize - 1] = userSize;



				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);
				std::swap(bonusArr, bonusArrTemp);
				std::swap(userIdArr, userIdArrTemp);



				delete[]loginArrTemp, passArrTemp, statusArrTemp, userIdArrTemp, bonusArrTemp;
				std::cout << "Èäåò ïîäãîòîâêà....";
				Sleep(2000);
				std::cout << "Ïîëüçîâàòåëü óñïåøíî äîáàâëåí\n\n";
				Sleep(1500);
				exit == false;
				break;

			}
			else if (choose == "2")
			{
				std::cout << "Îòìåíà\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
			if (exit == false)
			{
				break;
			}
		}

		if (exit == false)
		{
			break;
		}
	}

}

void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userId = 0, isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;

		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nÂûáåðèòå íîìåð ïîëüçîâàòåë äëÿ ñìåíû ïàðîëÿ èëè exit äëÿ âûõîäà - ";
		Getline(choose);

		if (choose == "exit")
		{
			std::cout << "Îòìåíà èçìåíåíèÿ ïàðîëÿ!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId<isAdmin || userId>userSize - 1)
			{
				std::cout << "Ïîëüçîâàòåëÿ ñ òàêèì íîìåðîì íå ñóùåñòâóåò \n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}

		while (true)
		{
			system("cls");

			if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
			{

				std::cout << "Íåëüçÿ ìåíÿòü ïàðîëü Àäìèíèñòðàòîðó!\n";
				Sleep(1500);
				break;
			}
			std::cout << "Ââåäèòå íîâûé ïàðîëü äëÿ ïîëüçîâàòåëÿ" << loginArr[userId] << " - ";
			Getline(newPass1);
			std::cout << "Ïîäòâåðäèòü íîâûé ïàðîëü äëÿ ïîëüçîâàòåëÿ" << loginArr[userId] << " - ";
			Getline(newPass2);
			if (CheckPass(newPass1) && CheckPass(newPass2))
			{
				if (newPass1 == newPass2 && newPass1 != passArr[userId] && newPass2 != passArr[userId])
				{
					passArr[userId] = newPass1;
					std::cout << "Óñïåøíî\n";
					Sleep(1500);
					break;
				}
			}
			else
			{
				std::cout << "Ïîâòîðèòå ïîïûòêó\nÏàðîëè íå îäèíàêîâûå èëè ñîâïîäàþò ñ äåéñòâóþùèì ïàðîëåì\n";
				Sleep(1500);
			}

		}


	}
}

void DeleteUser()
{
	std::string chooseId, checkPass, choose;
	int userId, isAdmin = 1;

	while (true)
	{
		if (currentStatus == userStatus[0] && userSize < 2)
		{
			std::cout << "Íåò äîñòóïíûõ ïîëüçîâàòåëåé äëÿ óäàëåíèÿ";
			Sleep(1500);
			return;
		}
		else if (currentStatus == userStatus[1] && staffCount < 1)
		{
			std::cout << "Íåò äîñòóïíûõ ïîëüçîâàòåëåé äëÿ óäàëåíèÿ";
			Sleep(1500);
			return;
		}
		ShowUsers();
		std::cout << "\nÂûáåðèòå íîìåð ïîëüçîâàòåëÿ äëÿ óäàëåíèå èëè exit äëÿ âûõîäà - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Îòìåíà óäàëåíèå ïîëüçîâàòåëÿ!\n";
			Sleep(1500);
			break;
		}

		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId<isAdmin || userId > userSize - 1)
			{
				std::cout << "Ïîëüçîâàòåëÿ ñ òàêèì íîìåðîì íå ñóùåñòâóåò\n";
				Sleep(1500);
				break;
			}

			while (true)
			{
				system("cls");
				if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
				{
					std::cout << "Íåëüçÿ óäàëèòü àäìèíèñòðàòîðà\n";
					Sleep(1500);
					break;
				}

				std::cout << "Óäàëåíèå ïîëüçîâàòåëÿ - " << loginArr[userId] << "\n\n";
				std::cout << "Äëÿ ïîäòâåðæäåíèÿ ââåäèòå ïàðîëü ñóïåð àäìèíèñòðàòîðà èëè exit äëÿ âûõîäà - ";
				Getline(checkPass);
				if (checkPass == "exit")
				{
					std::cout << "Îòìåíà óäàëåíèå ïîëüçîâàòåëÿ - " << loginArr[userId] << "\n";
					Sleep(1500);
					break;
				}
				else if (checkPass == passArr[0])
				{
					if (statusArr[userId] == userStatus[2])
					{
						staffCount--;
					}
					userSize--;

					std::string* loginArrTemp = new std::string[userSize];
					std::string* passArrTemp = new std::string[userSize];
					std::string* statusArrTemp = new std::string[userSize];
					double* bonusArrTemp = new double[userSize];
					unsigned int* userIdArrTemp = new unsigned int[userSize];

					for (size_t i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userId == c)
						{
							c++;
						}
						loginArrTemp[i] = statusArr[c];
						passArrTemp[i] = passArr[c];
						statusArrTemp[i] = statusArr[c];
						bonusArrTemp[i] = bonusArr[c];
						userIdArrTemp[i] = i + 1;
					}


					std::swap(loginArr, loginArrTemp);
					std::swap(passArr, passArrTemp);
					std::swap(statusArr, statusArrTemp);
					std::swap(bonusArr, bonusArrTemp);
					std::swap(userIdArr, userIdArrTemp);



					delete[]loginArrTemp, passArrTemp, statusArrTemp, userIdArrTemp, bonusArrTemp;
					std::cout << "Èäåò ïîäãîòîâêà....";
					Sleep(2000);
					std::cout << "Ïîëüçîâàòåëü óñïåøíî óäàëåí\n\n";
					Sleep(1500);
					break;


				}
				else
				{
					std::cout << "Íåêîðåêòíûé ïàðîëü!";
				}
			}
		}
		else
		{
			Err();
		}


	}

}

//------------------------------------------------------------------------

void createStorage()
{
	const int staticSize = 10;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Ak-47","Mp5","M4A1",
		"Deagle","Glok17","Double berrets","Cz","Five-Seven",
		"Flash","Molly"
	};
	unsigned int count[staticSize]{ 30,22,44,18,13,24,34,2,4,15 };
	double price[staticSize]{ 224.5,300.2,455.5,120.7,300.9,222.4,150.2,130.3,333.5,344.0 };

	if (isStorageCreate)
	{
		delete[]idArr, nameArr, counterArr, priceArr;
	}

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	counterArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreate = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(counterArr, count, storageSize);
	FillArray(priceArr, price, storageSize);

}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Íàçâàíèå òîâàðà \t" <<
			"Êîë-âî\t" << "Öåíà\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << counterArr[i] << "\t" << priceArr[i] << "\n";
		}
		Sleep(3000);
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Íàçâàíèå òîâàðà \t" <<
			"Êîë-âî\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << counterArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Íàçâàíèå òîâàðà \t" << "Öåíà\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] <<
				"\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Íàçâàíèå òîâàðà \t" << "\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\n";
		}
	}
}

void zeroCreateStorage()
{
	std::string choose;

	if (isStorageCreate)
	{
		delete[] idArr;
		delete[] nameArr;
		delete[] counterArr;
		delete[] priceArr;
		isStorageCreate = false;
	}

	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	counterArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];

	for (int i = 0; i < storageSize; i++)
	{
		idArr[i] = 0;
		nameArr[i] = "";
		counterArr[i] = 0;
		priceArr[i] = 0.0;
	}

	while (true)
	{
		AddNewItem();
		break;
	}

	isStorageCreate = true;

}

//----------------------------------------------------------

void Selling()
{
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0;
	int index = -1;
	double money = 0.0, totalSum = 0.0;
	bool isFirst = false;
	int sleeptimer = 0;

	while (true)
	{

		ShowStorage();
		std::cout << "\nÂâåäèòå ID òîâàðà äëÿ ïîêóïêè èëè exit äëÿ çàâåðøåíèå âûáîðà òîâàðà - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			system("cls");
			if (isFirst == false)
			{
				std::cout << "Âûõîä áåç ïîêóïîê\n";
				Sleep(1500);
				break;
			}
			if (totalSum > 5000)
			{
				totalSum = discounts(totalSum);
				std::cout << "\nÑóììà ñî ñêèäêîé ñîñòîâëÿåò - " << totalSum;
			}

			totalSum = birthdayDiscount(totalSum);
			system("cls");

			PrintCheck(totalSum);

			std::cout << "\nÏîäòâåðäèòü ïîêóïêó?\n 1 - Äà\n2 - Äîáàâèòü åùå òîâàð\n3 - Îòìåíà\nÂâîä - ";
			Getline(choose);
			if (choose == "1")
			{
				while (true)
				{

					system("cls");
					std::cout << "Âûáåðèòå ñïîñîá îïëàòû\n1 - Íàëè÷íûìè\n2 - Áåçíàë\nÂâîä - ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "Ê îïàëòå - " << totalSum << "\n\n";
						std::cout << "Ââåäèòè êîë-âî íàëè÷íûõ - ";
						Getline(chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stoi(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Íåäîñòàòî÷íî ñðåäñòâ!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "Ê ñîæåëåíèå íåòó ñòîëüêî ñäà÷è :( \n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Âàøè - " << money << "\n\n";
								Sleep(400);
								std::cout << "Îïëàòà ïðîøëà óñïåøíî. Ñäà÷à - " << money - totalSum << "ðóáëåé\n";
								Sleep(2000);
								cash += totalSum;
								cashIncome += totalSum;
								bonusArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}


					}
					else if (choose == "2")
					{
						std::cout << "Ïðèëîæèòå êàðòó\n\n";
						Sleep(1500);
						sleeptimer = 800;
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(sleeptimer);
								sleeptimer -= 100;
							}
							std::cout << "\nÑîåäèíåíèå íå óñòàíîâëåíî.Ïîâòîðèòå ïîïûòêó\n\n";
							Sleep(1500);
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(sleeptimer);
								sleeptimer -= 100;
							}
							std::cout << "\nÎïëàòà ïðîøëà óñïåøíî.Ñïàñèáî çà ïîêóïêó\n\n";
							system("pause");
							bankIncome += totalSum;
							bonusArr[currentId] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "aguzok" || choose == "Aguzok")
					{
						std::cout << "Àãóçîê îïëàòèò âàì ñ÷åò. Ãóäáàé!\n";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}

				}

				delete[]idArrCheck;
				delete[]nameArrCheck;
				delete[] countArrCheck;
				delete[] priceArrCheck;
				delete[] totalPriceArrCheck;

				idArrCheck = nullptr;
				nameArrCheck = nullptr;
				countArrCheck = nullptr;
				priceArrCheck = nullptr;
				totalPriceArrCheck = nullptr;
				checkSize = 0;

				break;
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Îòìåíà ïîêóïêè!\n";


				Sleep(1500);
				StorageReturner();
				system("cls");
				Sleep(1500);

				return;
			}
			else
			{
				Err();
				continue;
			}
		}
		if (IsNumber(chooseId))
		{
			id = stoi(chooseId) - 1;
			if (id<0 || id>storageSize - 1)
			{
				std::cout << "Îøèáêà ID\n";
				Sleep(1500);
				continue;

			}
		}
		else
		{
			continue;
		}

		std::cout << "\nÂâåäèòå êîë-âî òîâàðà èëè exit äëÿ âûáîðà äðóãîãî òîâàðà - ";
		Getline(chooseCount);

		if (chooseCount == "exit")
		{
			std::cout << "Îòìåíà ïîêóïêè òîâàðà - " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}

		if (IsNumber(chooseCount))
		{
			count = stoi(chooseCount);
			if (count<1 || count > counterArr[id])
			{
				std::cout << "Îøèáêà êîë-âî" << counterArr[id] << "\n";
				Sleep(1500);
				continue;

			}
		}
		else
		{
			continue;
		}

		CheckArrAppend();
		if (isFirst == false)
		{
			isFirst = true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		counterArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\n Òîâàð äîáàâëåí â ÷åê\n\n";
		Sleep(1000);

	}


}

void CheckArrAppend()
{

	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];

	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[checkSize];

	FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArray(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[]idArrCheckTemp;
	delete[]nameArrCheckTemp;
	delete[] countArrCheckTemp;
	delete[] priceArrCheckTemp;
	delete[] totalPriceArrCheckTemp;

}

void PrintCheck(double& totalSum)
{
	std::cout << "ID\t" << std::left << std::setw(25) << "Íàçâàíèå òîâàðà \t" <<
		"Öåíà çà åä\t" << "Öåíà\n" << "Èòîã\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] <<
			"\t" << priceArrCheck[i] << "\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "Èòîãî ê îïëàòå  - " << totalSum << "\n\n";

}

void StorageReturner()
{

	for (size_t i = 0; i < checkSize; i++)
	{
		counterArr[idArrCheck[i] - 1] += countArrCheck[i];

	}
	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;
}

double discounts(double& totalSum)
{
	if (totalSum > 5000)
	{
		return totalSum - (totalSum * 0.08);
	}
	else if (totalSum > 1500)
	{
		return totalSum - (totalSum * 0.15);
	}
	else if (totalSum > 25000)
	{
		return totalSum - (totalSum * 0.20);
	}
	else
	{
		return totalSum;
	}


}

double birthdayDiscount(double& totalSum)
{
	std::string choose;
	std::cout << "Ó âàñ ñåãîäíÿ Äåíü Ðîæäåíèå? \n Ââîä 1 - Äà èëè 2 - Íåò - ";
	Getline(choose);
	if (choose == "2")
	{
		std::cout << "Ê ñîæåëåíèþ ñêèäêè íå áóäåòü â ÷åñòü äíÿ ðîæäåíèÿ\n";
		return totalSum;
	}
	else if (choose == "1")
	{

		std::cout << "\nÑêèäêà â ÷åñòü äíÿ ðîæäåíèÿ ñîñòîâëÿåò - 12%\n";
		std::cout << "\nÑóììà ñî ñêèäêîé ñîñòîâëÿåò - " << totalSum - (totalSum * 0.12) << "\n";
		Sleep(2000);
		return totalSum - (totalSum * 0.12);

	}
	return totalSum;
}


//-----------------------------------------------------

void Start()
{

	std::string choose;

	while (true)
	{

		if (login())
		{
			if (currentStatus == userStatus[0])
			{
				while (true)
				{
					std::cout << "Âûáåðåòèå ñêëàä\n1 - Ãîòîâûé ñêëàä\n2 - Ñîçäàòü íîâûé\nÂâîä: ";
					Getline(choose);
					if (choose == "1")
					{

						if (isStorageCreate == false)
						{
							createStorage();
						}
						system("cls");
						ShowSuperAdminMenu();
						break;
					}
					else if (choose == "2")
					{
						if (isStorageCreate == false)
						{
							zeroCreateStorage();
						}
						system("cls");
						ShowSuperAdminMenu();
					}
					else
					{
						Err();
					}
				}
				createStorage();
			}
			else if (currentStatus == userStatus[1])
			{
				if (isStorageCreate == false)
				{
					createStorage();
				}
				system("cls");
				ShowAdminMenu();
			}
			else if (currentStatus == userStatus[2])
			{
				if (isStorageCreate == false)
				{
					createStorage();
				}
				system("cls");
				ShowUserMenu();
			}
		}
		else
		{
			system("cls");
			std::cout << "Ââåäèòå ïàðîëü ñóïåð àäìèíèñòðàòîðà äëÿ çàâåðøåíèÿ ñìåíû èëè \"exit\" äëÿ îòìåíû: ";
			Getline(choose);
			if (choose == passArr[0])
			{
				system("cls");
				std::cout << "Èòîãîâàÿ ïðèáûëü çà ñìåíó: " << cashIncome + bankIncome;
				std::cout << "\n\n\n\t\tÇàâåðøåíèÿ ðàáîòû ïðîãðàììû\n\n\n";
				Sleep(2000);
			}
			else if (choose == "exit")
			{
				continue;
			}
			else
			{
				Err();
			}
			std::cout << "Çàâåðøåíèå ðàáîòû ïðîãðàììû\n\n\n";
		}

	}
}

bool login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "\n\n\nÌàãàçèí Pistoletiki\n\n\n";
		std::cout << "Ââåäèòå ëîãèí ";
		Getline(login);
		std::cout << "Ââåäèòå ïàðîëü ";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}


		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Ïîëüçîâàòåëü " << loginArr[i] << "\n\nÄîáðî ïîæàëîâàòü\n\n";
				std::cout << "Íàø ñòàòóñ " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentId = userIdArr[i];
				return true;
			}
		}
		Err();

	}
}

bool logout()
{
	std::string choose;
	system("cls");
	while (true)
	{
		std::cout << "Äëÿ ïîäòâåðæäåíèÿ âûõîäà ââåäèòå ñâîé ïàðîëü èëè exit äëÿ âîçðàòà â ìåíþ - ";
		Getline(choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err();
		}
	}



}

void SetLoginSymbols()
{

	for (char i = '0'; i <= '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	isLoginSetCreated = true;
}

void SetPassSymbols()
{
	for (char i = '!'; i <= '&'; i++)
	{
		passSymbols.insert(i);
	}

	for (char i = '('; i <= '+'; i++)
	{
		passSymbols.insert(i);
	}

	for (char i = '/'; i <= '~'; i++)
	{
		passSymbols.insert(i);
	}
	isPassSetCreated = true;
}

void ShowIncome()
{
	system("cls");
	std::cout << "Òåêóùàÿ ïðèáûëü çà ñìåíó\n\n";
	std::cout << "Íàëè÷íûé ðàñ÷åò - " << cashIncome << "\n";
	std::cout << "Áåçíàëè÷íûé ðàñ÷åò - " << bankIncome << "\n";
	std::cout << "Èòîãî - " << bankIncome + cashIncome << "\n";
	std::cout << "Ñóììà âàøèõ ïðîäàæ - " << bonusArr[currentId] << "\n\n";

	system("pause");
	system("cls");

}

bool CheckLogin(const std::string& str)
{
	if (str.size() < 5 || str.size() > 20)
	{
		std::cout << "Îøèáêà äëèíû ëîãèíà\n";
		Sleep(1500);
		return false;
	}
	for (char sym : str)
	{
		if (!loginSymbols.count(sym))
		{
			std::cout << "Íåêîðåòíûé ëîãèí\n";
			Sleep(1500);
			return false;
		}
	}

	for (size_t i = 0; i < userSize; i++)
	{
		if (str == nameArr[i])
		{
			std::cout << "Òàêîé ïîëüçîâàòåëü óæå ñóùåñòâóåò!\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool CheckPass(const std::string& str)
{
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Îøèáêà äëèíû ïàðîëÿ\n";
		Sleep(1500);
		return false;
	}

	int numCount = 0;
	int symCount = 0;
	std::unordered_set<char> specialSymbols{ '!','@','#','$','%','^','&','*','(',')','-','_','+','=','/','?','|','\\','\"',
	'\'',',','.','<','>','~','`',';',':','{','}','[',']' };

	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Íåêîðåòíûé ïàðîëü\n";
			Sleep(1500);
			return false;
		}
		if (std::isdigit(sym))
		{
			numCount++;
		}
		if (specialSymbols.count(sym))
		{
			symCount++;
		}

	}
	if (numCount > 2 && symCount > 2)
	{
		return true;
	}
	else
	{
		std::cout << "Ìèíèìóì 3 ñèìâîëà è 3 öèôðû";
		Sleep(1500);
		return false;
	}

	return true;
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Íà÷àòü ïðîäàæó\n";
		std::cout << "2 - Ïîêàçàòü ñêëàä\n";
		std::cout << "3 - Ïîïîëíèòü ñêëàä\n";
		std::cout << "4 - Ñïèñàòü òîâàð\n";
		std::cout << "5 - Èçìåíèòü öåíó\n";
		std::cout << "6 - Ðåäàêòèðîâàòü ñêëàä\n";
		std::cout << "7 - Ðåäàêòèðîâàòü ïåðñîíàë\n";
		std::cout << "8 - Îò÷åò î ïðèáûëè\n";
		std::cout << "0 - Çàêðûòü ñìåíó\n";
		std::cout << "Ââîä - ";
		Getline(choose);
		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Ñêëàä ïóñòîé!\n";
			}
			Err();
		}
	}

}

void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Íà÷àòü ïðîäàæó\n";
		std::cout << "2 - Ïîêàçàòü ñêëàä\n";
		std::cout << "3 - Ïîïîëíèòü ñêëàä\n";
		std::cout << "4 - Ñïèñàòü òîâàð\n";
		std::cout << "5 - Ðåäàêòèðîâàòü ñêëàä\n";
		std::cout << "6 - Ðåäàêòèðîâàòü ïåðñîíàë\n";
		std::cout << "7 - Îò÷åò î ïðèáûëè\n";
		std::cout << "0 - Çàêðûòü ñìåíó\n";
		std::cout << "Ââîä - ";
		Getline(choose);
		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{
			ChangeStorage();
		}
		else if (choose == "6")
		{
			ChangeUsers();
		}
		else if (choose == "7")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Ñêëàä ïóñòîé!\n";
			}
			Err();
		}
	}
}

void ShowUserMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Íà÷àòü ïðîäàæó\n";
		std::cout << "2 - Ïîêàçàòü ñêëàä\n";
		std::cout << "3 - Îò÷åò î ïðèáûëè\n";
		std::cout << "0 - Çàêðûòü ñìåíó\n";
		std::cout << "Ââîä - ";
		Getline(choose);
		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Ñêëàä ïóñòîé!\n";
			}
			Err();
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Îøèáêà äëèíà ÷èñëà, ìàêñèìóì äåâÿòèçíà÷íûå ÷èñëà\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Âûøå ÷èñëî íå ÿâëÿåòñÿ ÷èñëîì!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

void AddStorageItem()
{
	std::string chooseID, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Ââåäèòå id òîâàðà èëè \"exit\" äëÿ âûõîäà ";
		Getline(chooseID);

		if (chooseID == "exit")
		{
			std::cout << "Îòìåíà îïåðàöèè äëÿ ïîïîëíåíèÿ!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Ââåäèòå êîë-âî òîâàðà äëÿ ïîïîëíåíèÿ ";
		Getline(chooseCount);

		if (IsNumber(chooseID) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseID) - 1;
			count = std::stoi(chooseCount);

			if (id<0 || id>storageSize - 1 || count < 0 || count>300)
			{
				std::cout << "Íåêîððåêòíûé id èëè êîë-âî \n Ìàêñèìàëüíîå êîë-âî òîâàðîâ 300 \n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< counterArr[id] << "---->" << counterArr[id] + count << "\n\n";
				std::cout << "Ïîäòâåðäèòü? \n1-äà \n2 íåò\n Ââîä - ";
				Getline(choose);
				if (choose == "1")
				{
					counterArr[id] += count;
					std::cout << "Òîâàð óñïåøíî ïîïîëíåí";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Îòìåíà ïîïîëíåíèÿ òîâàðà\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}

}

void RemoveStorageItem()
{
	std::string chooseID, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Ââåäèòå id òîâàðà èëè \"exit\" äëÿ âûõîäà ";
		Getline(chooseID);

		if (chooseID == "exit")
		{
			std::cout << "Îòìåíà îïåðàöèè äëÿ ñïèñàíèÿ!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Ââåäèòå êîë-âî òîâàðà äëÿ ñïèñàíèÿ ";
		Getline(chooseCount);

		if (IsNumber(chooseID) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseID) - 1;
			count = std::stoi(chooseCount);

			if (id<0 || id>storageSize - 1 || count < 0 || count>counterArr[id])
			{
				std::cout << "Íåêîððåêòíûé id èëè êîë-âî \n Ìàêñèìàëüíî êîë-âî äëÿ ñïèñàíèÿ òîâàðîâ - \n"
					<< counterArr[id] << "\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< counterArr[id] << "---->" << counterArr[id] - count << "\n\n";
				std::cout << "Ïîäòâåðäèòü? \n1-äà \n2 íåò\n Ââîä - ";
				Getline(choose);
				if (choose == "1")
				{
					counterArr[id] -= count;
					std::cout << "Òîâàð óñïåøíî ñïèñàí";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Îòìåíà ñïèñàíèÿ òîâàðà\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseID, choosePrice, choose;
	unsigned int id = 0;
	double newPrice = 0.0;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Ââåäèòå id òîâàðà èëè \"exit\" äëÿ âûõîäà ";
		Getline(chooseID);

		if (chooseID == "exit")
		{
			std::cout << "Îòìåíà îïåðàöèè äëÿ èçìåíåíèÿ öåíû!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Ââåäèòå íîâóþ öåíó òîâàðà ";
		Getline(choosePrice);

		if (IsNumber(chooseID) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseID) - 1;
			newPrice = std::stod(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0.0 || newPrice > 200000.99)
			{
				std::cout << "Íåêîððåêòíûé id èëè êîë-âî \n Ìàêñèìàëüíî öåíà òîâàð - 200000.99 \n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << nameArr[id] << "\t"
					<< priceArr[id] << "---->" << newPrice << "\n\n";
				std::cout << "Ïîäòâåðäèòü? \n1-äà \n2 íåò\n Ââîä - ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = newPrice;
					std::cout << "Öåíà óñïåøíî èçìåíåíà";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Îòìåíà èçìåíåíèÿ öåíû\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Äîáàâèòü íîâûé òîâàð\n";
		std::cout << "2 - Èçìåíèòü íàçâàíèå òîâàðà\n";
		std::cout << "3 - Óäàëèòü òîâàð\n";
		std::cout << "0 - Âûõîä èç ðåäàêòîðà\n";
		std::cout << "Ââîä - ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Ñêëàä ïóñòîé!\n";
			}
			Err();
		}
	}


}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit;

	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tÄîáàâëåíèå íîâîãî òîâàðà\nÂâåäèòå exit äëÿ ïðåêðàùåíèå îïåðàöèè\n\n";
			std::cout << "Ââåäèòå íàçâàíèå íîâîãî òîâàðà - ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "Îïåðàöèÿ äîáàâëåíèÿ òîâàðà ïðåêðàùåíà!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Îøèáêà èìåíè.Ìàêñèìàëüíàÿ äëèíà 60 ñèìâîëîâ";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tÄîáàâëåíèå íîâîãî òîâàðà\nÂâåäèòå exit äëÿ ïðåêðàùåíèå îïåðàöèè\n\n";
			std::cout << "Ââåäèòå êîë-âî íîâîãî òîâàðà - ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "Îïåðàöèÿ äîáàâëåíèÿ òîâàðà ïðåêðàùåíà!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 300 || count < 0)
				{
					std::cout << "Îøèáêà ìàêñèìàëüíîãî êîë-âî òîâàðîâ. Íå áîëåå 300 åä";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "\tÄîáàâëåíèå íîâîãî òîâàðà\nÂâåäèòå exit äëÿ ïðåêðàùåíèå îïåðàöèè\n\n";
			std::cout << "Ââåäèòå öåíó íîâîãî òîâàðà - ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "Îïåðàöèÿ èçìåíåíèÿ öåíû òîâàðà ïðåêðàùåíà!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 200000.99 || price < 0)
				{
					std::cout << "Îøèáêà ìàêñèìàëüíîé öåíû òîâàðîâ. Íå áîëåå 200000.99 ðóá";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Íîâûé òîâàð " << newName << "\n";
			std::cout << "Êîë-âî " << count << "\n";
			std::cout << "Öåíà " << newPrice << "\n";
			std::cout << "Ïîäòâåðäèòü?\n1 - Äà 2 - Íåò\nÂâîä: ";
			Getline(choose);
			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				FillArray(idArrTemp, idArr, storageSize - 1);
				FillArray(nameArrTemp, nameArr, storageSize - 1);
				FillArray(countArrTemp, counterArr, storageSize - 1);
				FillArray(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(counterArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Èäåò ïîäãîòîâêà....";
				Sleep(2000);
				std::cout << "Òîâàð óñïåøíî äîáàâëåí\n\n";
				Sleep(1500);
				break;

			}
			else if (choose == "2")
			{
				std::cout << "Îòìåíà";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}
}

void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);

		std::cout << "\nÂâåäèòå id òîâàðà èëè exit äëÿ âûõîäà - ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Îòìåíà îïåðàöèè ñìåíû íàçâàíèÿ!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Ââåäèòå íîâîå íàçâàíèå òîâàðà - ";
		Getline(newName);
		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "Îøèáêà èìåíè.Ìàêñèìàëüíàÿ äëèíà 60 ñèìâîëîâ";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>storageSize - 1)
			{
				std::cout << "Îøèáêà ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << " ----> " << newName << "\n\n";
				std::cout << "Ïîäâåðäèòü? \n1 - äà\n2- íåò\nÂâîä ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Ñìåíà íàçâàíèÿ çàâåðøåíà";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Îòìåíà îïåðàöèè\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}

			}
		}


	}



}

void DeleteItem()
{
	std::string chooseID, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nÂâåäèòå Id òîâàðà äëÿ óäàëåíèå èëè exit äëÿ âûõîäà";
		Getline(chooseID);
		if (chooseID == "exit")
		{
			std::cout << "Îòìåíà îïåðàöèè óäàëåíèå òîâàðà";
			Sleep(1500);
			break;
		}

		if (IsNumber(chooseID))
		{
			id = std::stoi(chooseID) - 1;
			if (id<0 || id>storageSize - 1)
			{
				std::cout << "Îøèáêà id\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Òîâàð íà óäàëåíèå - " << nameArr[id] << "\n\n";
				std::cout << "Ïîäòâåðäèòü?\n1-äà\n2-íåò\nÂâîä - ";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];

					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = counterArr[c];
						priceArrTemp[i] = priceArr[c];
					}

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(counterArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Èäåò ïîäãîòîâêà....";
					Sleep(2000);
					std::cout << "Òîâàð óñïåøíî óäàëåí\n\n";
					Sleep(1500);
					break;


				}
				else if (choose == "2")
				{
					std::cout << "Îòìåíà";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}


}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');

}

inline void Err(int time)
{
	std::cout << "Íåêîðåêòíûé ââîä\n\n";
	Sleep(time);
	system("cls");
}

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArray[i] = staticArray[i];
	}
}
