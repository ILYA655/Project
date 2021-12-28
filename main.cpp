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
    
    int ch;
	  pos(a);
    while(true){
        do {
            ch = mygetch();
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
                    check();
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
	cout << "Автозаполнение" << endl;
	cout << "размер графа: ";
	cin >> n;
	cout << endl;
	
	t = create(n);
	cout << endl;
	mainmenu();
}

void size_M(){
    n = 0;
	cout << "Ручное заполнение" << endl;
    cout << "размер графа: ";
    cin >> n;
    cout << endl;
	
	t = m_create(n);
    cout << endl;
    pos(0);
}

int** create(int n){
	int k = 1;
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
    int k = 1;
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


int gamilton(int k, int* path, int* c){
    int v;
    int q = 0;
    for (v = 0; v < n && !q; v++){
        if (G1[v][path[k - 1]] || G1[path[k - 1]][v]){
            if (k == n && v == v0)
                q = 1;
            else
                if (c[v] == -1){
                    c[v] = 1;
                    path[k] = v;
                    q = gamilton(k + 1, path, c);
                    if (!q)
						c[v] = -1;
                }
                else
                    continue;
        }
    }   return q;
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
	cout << "данные сохранены" << endl;
	fout.close();
	mainmenu ();
}

void check(){
	int a = 0, b = 0, s = 1, l = 1, x = 0;
    if (n >= 3){
        for (int i = 0; i < n; i++){
            for (int j = s; j < n; j++){
                if (G[i][j] == 0){
					x++;
                    for (int p = 0; p < n; p++){
                        if (G[i][p] == 1)
                            a++;
                        if (G[j][p] == 1)
                            b++;
                    }
					if (a + b >= n){
						prepare(n);
						return;
					}
                }
            }
            s++;
            a = 0; b = 0;
        }
		l++;
		s = l;
    }
	if (x == 0){
		prepare(n);
		return;
	}
	else{
		cout << "нет цикла" << endl;
		return;
	}
		
	
	
}

void prepare(int n){
	int* c = (int*)malloc(n * sizeof(int));
	int* path = (int*)malloc(n * sizeof(int));
	for (int j = 0; j < n; j++)
		c[j] = -1;
	cout << endl << "с какой вершины начать обход?" << endl;
    cin >> v0;
    path[0] = v0;
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
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fin >> G1[i][j];
	}
	fin.close();
	cout << "гамильтонов цикл:" << endl;
    if (gamilton(1, path, c))
        printGam(path);
    else{
		er = 1;
		cout << "нет решений" << endl;
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
	cout << "результат сохранен" << endl;
	fout.close();
	mainmenu();
}

int main(){
	mainmenu();
}

