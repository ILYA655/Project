#include "header.hpp"
int n, er;
int v0;

int **t;
int **G;
int **G1;
int a = 0;

int* res = (int*)malloc(n * sizeof(int));

enum
{
  KEY_UP    = 65,
  KEY_DOWN  = 66,
  ENTER  = 10
};

int mygetch(){
    struct termios oldt,newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = cin.get();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

void pos(int a) {

	if (a == 0) {
		system("clear");
		cout << 
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>       РУЧНОЕ ЗАПОЛНЕНИЕ       <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |              автозаполнение              |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             сохранение данных            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          поиск гамильтонова цикла        |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            сохранить результат           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  выход                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 1) {
		system("clear");
		cout << 
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             ручное заполнение            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>        АВТОЗАПОЛНЕНИЕ         <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             сохранение данных            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          поиск гамильтонова цикла        |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            сохранить результат           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  выход                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 2) {
		system("clear");
		cout <<
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             ручное заполнение            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |              автозаполнение              |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>       СОХРАНЕНИЕ ДАННЫХ       <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          поиск гамильтонова цикла        |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            сохранить результат           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  выход                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 3) {
		system("clear");
		cout <<
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             ручное заполнение            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |              автозаполнение              |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             сохранение данных            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>   ПОИСК ГАМИЛЬНТОНОВА ЦИКЛА   <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            сохранить результат           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  выход                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 4) {
		system("clear");
		cout <<
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             ручное заполнение            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |              автозаполнение              |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             сохранение данных            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          поиск гамильтонова цикла        |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>      СОХРАНИТЬ РЕЗУЛЬТАТ      <<   |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |                  выход                   |\n"
			"                                        \\                                          /\n";
	}
	if (a == 5) {
		system("clear");
		cout <<
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             ручное заполнение            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |              автозаполнение              |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |             сохранение данных            |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |          поиск гамильтонова цикла        |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |            сохранить результат           |\n"
			"                                        \\                                          /\n"
			"                                                                                     \n"
			"                                        /                                          \\\n"
			"                                        |    >>            ВЫХОД              <<   |\n"
			"                                        \\                                          /\n";
	}
}

int mainmenu () {
    
    int ch;// = mygetch();
    //int a = 0;
	  pos(a);
    while(true){
        //c = 0;
        do {
                //c = getchar();
            ch = mygetch();
			//a = 0;
                switch(ch){
                    case KEY_UP:
                        if (a == 0){
                            a = 6;
                            pos(a);
                        }
                        if (a > 0){
                            a = a - 2;
                            pos(a);
                        }
                    case KEY_DOWN:
                        if (a < 6){
                            a++;
                            pos(a);
                        }
                        if (a == 6){
                            a = 0;
                            pos(a);
                        }
                    default:
                        break;
                }
            } while (ch != ENTER);
                if (a == 0)
                {
                    system("clear");
					a = -1;
                    size_M();

                }
                if (a == 1)
                {
                    system("clear");
					a = -1;
                    size_A();
                    
                    //break;
                }
                if (a == 2)
                {

                    system("clear");
					a = -1;
                    save_data(n);
                }
                if (a == 3)
                {
                	system("clear");
					a = -1;
                    prepare(n);
                }
                if (a == 4)
                {
                    system("clear");
					a = -1;
                    save_res();
                }
                if (a == 5)
                {
					system("clear");
					exit(3);
                }
        }

    return 0;
}

void size_A(){
    n = 0;
    cout << "размер графа: ";
    cin >> n;
    cout << endl;
	cout << "Автозаполнение" << endl;
    t = create(n);
    cout << endl;
    mainmenu();
}

void size_M(){
    n = 0;
    cout << "размер графа: ";
    cin >> n;
    cout << endl;
	cout << "Ручное заполнение" << endl;
	t = m_create(n);
    cout << endl;
    pos(0);
}

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
	for (int i = 0; i < n; i++)
        res[i] = path[i];
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

void save_data(int n){
	ofstream fout;
	fout.open("data.txt");
	for (int i = 0; i < n; i++){
		fout << endl;
		for (int j = 0; j < n; j++){
			fout << G[i][j] << "  ";
		}
	}
	fout.close();
	mainmenu ();
}

void prepare(int n){
	int* c = (int*)malloc(n * sizeof(int));           // номер хода, на котором посещается вершина
	int* path = (int*)malloc(n * sizeof(int));			// номера посещаемых вершин
	for (int j = 0; j < n; j++)
		c[j] = -1;                       //помечаем, что все вершины не пройдены
	//t = m_create(n);
	cout << endl << "с какой вершины начать обход?" << endl;
    cin >> v0;
    path[0] = v0;                           //начинаем путь с вершины v0
    c[v0] = v0;
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
	cout << "Gamilton's circle:" << endl;                             // и она пройдена
    if (gamilton(1, path, c))               //ищем путь, начиная с прохода 1
        printGam(path);
    else{
		er = 1;
		cout << "No solutions" << endl;
	}
	cout << endl;
	mainmenu();
}

void save_res(){
	ofstream fout;
	fout.open("result.txt");
	fout << "результат поиска:" << endl;
	if (er == 1){
		fout << "нет решений";
	}
	else{
		for (int i = 0; i < n; i++){
		fout << res[i] << "  ";
		}
		fout << res[0];
	}
	fout.close();
	mainmenu();
}

int main(){
	mainmenu();
}
