#include "header.hpp"

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

void size_A(){
    int n = 0;
    cout << "размер графа: ";
    cin >> n;
    cout << endl;
    create(n);
    cout << endl;
    mainmenu();
}

void size_M(){
    int n = 0;
    cout << "размер графа: ";
    cin >> n;
    cout << endl;

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

int mainmenu(){
	struct termios newt, oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int a = 0;
	pos(a);
    int c = 0;
    while(true){
        do {
            c = cin.get();
        
            switch(c){
                case 'A':
                    if (a == 0){
                        a = 6;
                        pos(a);
                    }
                    if (a > 0){
                        a = a - 2;
                        pos(a);
                    }
                case 'B':
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
        } while (c != 10);
            if (a == 0)
            {
                system("clear");
                //size_A();
            }
            if (a == 1)
            {
                system("clear");
                size_A();
                
                //break;
            }
            if (a == 2)
            {

                system("clear");
                //prnt();
            }
            if (a == 3)
            {
               system("clear");
                //prepare();
            }
            if (a == 4)
            {
                system("clear");
                //read_file();
            }
            if (a == 5)
            {
                system("clear");
                break;
            }
        
            
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return EXIT_SUCCESS;
}



int main(){
	mainmenu();
	return 0;
}
