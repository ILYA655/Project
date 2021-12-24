#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>

using namespace std;
 
const int n=5;
 
int c[n] ;   // номер хода, на котором посещается вершина
int path[n]; // номера посещаемых вершин
int v0=0;    // начальная вершина
 
//Матрица смежности
int a[n][n] = 
{
    0,1,1,0,0,
	1,0,0,1,0,
	1,0,0,1,1,
	0,1,1,0,1,
    0,0,1,1,0
};

void prnt(void){
	int p;
	for (p = 0; p<n; p++){
		cout  <<  path[p] + 1  <<  "\t";
		cout  <<  path[0] + 1;
    	cout  <<  endl;
	}
	 		
}

int gamilton (int k)
{
	int v, q1 = 0;
    for(v = 0; v < n && !q1; v++)
    {
    	if(a[v][path[k-1]] || a[path[k-1]][v])
    	{
    		if (k == n &&  v == v0 )
				q1 = 1;
			else if (c[v] == -1) 
			{
				c[v] = k;
				path[k] = v;
				q1 = gamilton (k+1);
				if (!q1) c[v] = -1;
			}
			else continue;
    	}
    }
	return q1;
}

int** create(int n)
{
	int** G, k = 1;
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++){
			if (rand() % 100 > 50){
				G[i][j] = 0;
			}
			else{
				G[i][j] = 1;
			}
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++){
		for (int j = k; j < n; j++){
			G[j][i] = G[i][j];
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";

	for (int i = 0; i < n; i++){
		cout << "\n";
		for (int j = 0; j < n; j++){
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

int** m_create(int n)
{
	int **G, k = 1, num, x = 0;
	char o[5] = "   ";
	G = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";
	cout << endl;
	for (int i = 0; i < n; i++){
		G[i] = (int*)malloc(n * sizeof(int));

		G[i][i] = 0;
		
		cout << G[i][i];
		for (int j = k; j < n; j++){
			cout << "  ";
			cin >> x;
			//cout << "  ";
			G[i][j] = x;
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < n; i++){
		for (int j = k; j < n; j++){
			G[j][i] = G[i][j];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";
	for (int i = 0; i < n; i++){
		cout << "\n";
		for (int j = 0; j < n; j++){
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

void prepare(){
	cout << "Гамильтонов цикл:\n";
        for(int j = 0; j < n; j++)
			c[j] = -1;
    path[0] = v0;
    c[v0] = v0;
	if (gamilton(1)) prnt(); else cout << "Нет решений\n";
}

void pos(int a) {

	if (a == 0) {
		system("cls");
		cout << 
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>      ÑÎÇÄÀÒÜ ÁÀÇÓ ÄÀÍÍÛÕ      <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 1) {
		system("cls");
		cout << 
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>      ÎÒÊÐÛÒÜ ÁÀÇÓ ÄÀÍÍÛÕ      <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 2) {
		system("cls");
		printf("\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>    ÏÎÑÌÎÒÐÅÒÜ ÁÀÇÓ ÄÀÍÍÛÕ     <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n");
	}
	if (a == 3) {
		system("cls");
		printf("\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>     ÑÎÕÐÀÍÈÒÜ ÁÀÇÓ ÄÀÍÍÛÕ     <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n");
	}
	if (a == 4) {
		system("cls");
		printf("\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>     ÇÀÃÐÓÇÈÒÜ ÁÀÇÓ ÄÀÍÍÛÕ     <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n");
	}
	if (a == 5) {
		system("cls");
		printf("\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>     ÐÀÁÎÒÀ Ñ ÁÀÇÎÉ ÄÀÍÍÛÕ     <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  âûõîä                   |\n"
			"                                        \\                                          /\n");
	}
	if (a == 6) {
		system("cls");
		printf("\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            ñîçäàòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            îòêðûòü áàçó äàííûõ           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          ïîñìîòðåòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ñîõðàíèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           çàãðóçèòü áàçó äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |           ðàáîòà ñ áàçîé äàííûõ          |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>            ÂÛÕÎÄ              <<   |\n"
			"                                        \\                                          /\n");
	}
}

void mainmenu(int n)
{
	int a = 0;
	pos(a);
	while (true)
	{
		char keybd;
		do {
			keybd = cin.get();
			if (keybd == 80) {
				if (a < 7) {
					a = a + 1;
					pos(a);
				}
				if (a == 7) {
					a = 0;
					pos(a);
				}
			}
			if (keybd == 72) {
				if (a == 0) {
					a = 7;
					pos(a);
				}
				if (a > 0) {
					a = a - 1;
					pos(a);
				}
			}
		} while (keybd != 13);
		if (a == 0)
		{
			system("cls");
			create(n);
		}
		if (a == 1)
		{
			system("cls");
			m_create(n);
		}
		if (a == 2)
		{

			system("cls");
			prnt();
		}
		if (a == 3)
		{
			system("cls");
			prepare();
		}
		if (a == 4)
		{
			system("cls");
			//read_file();
		}
		if (a == 5)
		{
			system("cls");
			//menu();
		}
		if (a == 6)
		{
			system("cls");
			exit(1);
		}
		
	}
}



//подпрограмма нахождения гамильтонова цикла




int main(){
	int j, n, n1, ** t, ** t1, ** t2, ** t3, ** t4, o, u;
	mainmenu(n);
	/*
	char am1[] = "r";
	char am2[] = "e";
	char ch[2];
	cout << "random or manual enter? (""r"" is random, ""e"" is manual enter)" << endl;
	cin >> ch;
	if (strcmp(ch, am1) == 0){
		cout << "Enter array size: ";
		cin >> n;
		t = create(n);
		cout << endl;
	}
	else if (strcmp(ch, am2) == 0){
			cout << "Enter array size: ";
			cin >> n;
			t1 = m_create(n);
			cout << endl;
		}
		else{
			cout << "No such variant" << endl;
		}
	*/
    /*cout << "Гамильтонов цикл:\n";
        for(j=0; j<n; j++)
			c[j] = -1;
    path[0]=v0;
    c[v0]=v0;
    if (gamilton(1)) prnt(); else cout << "Нет решений\n";*/
    //cin.get();
	return 0;
}
