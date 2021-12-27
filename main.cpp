#include <iostream>
#include <fstream>
 
using namespace std;

int n;
int v0;

int **t;
int **G;
int **G1;

int** create(int n){
	// int** G, k = 1;
	int k = 0;
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

int** m_create(int n){
	//int **G, 
    int k = 1, num, x = 0;
	G = (int**)malloc(n * sizeof(int*));	
	cout << endl;
	for (int i = 0; i < n; i++){
		G[i] = (int*)malloc(n * sizeof(int));
		G[i][i] = 0;
		for (int j = k; j < n; j++){
			cin >> G[i][j];
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
    cout << endl;
	for (int i = 0; i < n; i++)
		cout << "V" << i << " ";
	for (int i = 0; i < n; i++){
		cout << endl;
		for (int j = 0; j < n; j++){
			cout << G[i][j] << "  ";
		}
	}
	return G;
}

void printGam(int* path)
{
    int p;
    for (p = 0; p < n; p++)
        cout << path[p] << " ";
    cout << path[0];
    cout << endl;
}

void printGam_s(int* path)
{
	ofstream res;
	res.open("result.txt");
    int p;
    for (p = 0; p < n; p++)
        res << path[p] << " ";
    res << path[0];
    res << endl;
	res.close();
}

//подпрограмма нахождения гамильтонова цикла
//k - номер прохода или количество найденных вершин пути, результат - массив path, возвращвет признак нахождения пути
int gamilton(int k, int* path, int* c) 
{
    int v;          //индекс вершины
    int q1 = 0;     //признак нахождения пути, сначала - не найдено
    for (v = 0; v < n && !q1; v++) // обход матрицы по всем вершинам и пока не найден путь
    {
        //есть ли ребро между текущей вершиной и вершиной, найденной при предыдущем вызове
        //если граф неориентированный, то оба используемых элемента матрицы должны быть равны
        //если ориентированный, то, по идее, надо смотреть только a[path[k - 1]][v]
        if (G1[v][path[k - 1]] || G1[path[k - 1]][v]) 
        {
            if (k == n && v == v0)          //если обошли все вершины и дошли до начальной,
                q1 = 1;                     // то путь найден
            else
                if (c[v] == -1)             //формируем путь, если в вершине v еще не были
                {
                    c[v] = k;               //номер прохода
                    path[k] = v;            //занесение вершины в найденный путь
                    q1 = gamilton(k + 1, path, c);   //ищем следующую вершину
                    if (!q1) c[v] = -1;     //если путь не найден, то помечаем текущую вершину, как непройденную
                }
                else
                    continue;               //если в вершине уже были, то на анализ следующей вершины
        }
    }   return q1;                          //возвращаем нашли или нет
}
 
int main(){
    int p = 0;
	char a;
    int* c = (int*)malloc(n * sizeof(int));           // номер хода, на котором посещается вершина

    //int path[n];
    int* path = (int*)malloc(n * sizeof(int));			// номера посещаемых вершин

	ofstream fout;
	fout.open("data.txt");  
	cout << "сколько элементов ";
	cin >> n;
	cout << endl;
	
	for (int j = 0; j < n; j++)
		c[j] = -1;                       //помечаем, что все вершины не пройдены
	t = m_create(n);;
	for (int i = 0; i < n; i++){
		fout << endl;
		for (int j = 0; j < n; j++){
			fout << G[i][j] << "  ";
		}
	}
	fout.close();
	cout << endl;
	ifstream fin;
    fin.open("data.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
	else {
		cout << "Файл открыт" << endl;
		G1 = new int*[n];
		for (int i = 0; i < n; i++)
			 G1[i] = new int[n];

		//Считаем матрицу из файла
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fin >> G1[i][j];

		//Выведем матрицу
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 		cout << G1[i][j] << "  ";
		// 	cout << endl;
		// }
	}
	fin.close();

    cout << endl << "c xtuj yfxfnm" << endl;
    cin >> v0;
    path[0] = v0;                           //начинаем путь с вершины v0
    c[v0] = v0;
	cout << "Gamilton's circle:" << endl;                             // и она пройдена
    if (gamilton(1, path, c))               //ищем путь, начиная с прохода 1
        printGam(path);
    else
        cout << "No solutions" << endl;
		cout << endl;
	ofstream res;
	res.open("result.txt");
	if (gamilton(1, path, c))               //ищем путь, начиная с прохода 1
        printGam_s(path);
    else
        fout << "No solutions" << endl;
	fout.close();
}
