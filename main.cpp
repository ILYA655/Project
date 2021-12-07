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

//подпрограмма нахождения гамильтонова цикла
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
 
int main(){
	int j, n, n1, ** t, ** t1, ** t2, ** t3, ** t4, o, u;
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
	
    cout << "Гамильтонов цикл:\n";
        for(j=0; j<n; j++)
			c[j] = -1;
    path[0]=v0;
    c[v0]=v0;
    if (gamilton(1)) prnt(); else cout << "Нет решений\n";
    //cin.get();
	return 0;
}
