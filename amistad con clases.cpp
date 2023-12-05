#include <iostream>
#include<fstream>
using namespace std;

class Gerente; 
class Vendedor; 
class Operario; 
class Operario {
    char nom[40];
    int Id;
    int salario;
    float hs , ho , hon , hd , hdn ,sd,pe,ht;
	long int st;

public:
	Operario();
	~Operario();
    void Leer(void);
    void Proceso(void);
    void Imprimir(void);
   friend class  Promedio; 
    friend class  archivo;
    friend class vocal;
};

class Vendedor {
    char nom[40];
    int Id;
    int salario;
    float sd,pn;
    long int st;
    int h,s;

public:
	Vendedor();
	~Vendedor();
    void Leer();
    void Proceso();
    void Imprimir();
  	friend class Promedio; // Declaración de amistad
    friend class archivo;
    friend class  vocal;
};

class Gerente {
    char nom[40];
    int Id;
    int salario;
    long int st;
    float sd,pn;

public:
	Gerente();
	~Gerente();
    void Leer(void);
    void Proceso(void);
    void Imprimir(void);
   friend class  Promedio; // Declaración de amistad
   friend class archivo;
	friend class  vocal;
};
class Promedio{
	public:
		void promedio(Operario,Vendedor,Gerente);
};
void Promedio::promedio(Operario x ,Vendedor y,Gerente z){
	float pr = 0.0;
    pr = (x.salario + y.salario + z.salario) / 3.0;
    cout << "El promedio de salarios es: " << pr << endl;
}
class archivo{
	public:
		void archi(Operario ,Vendedor ,Gerente );
};
void archivo::archi(Operario x ,Vendedor y,Gerente z){
	ofstream nomi("nomina.txt",ios::app);
	if(nomi.is_open()){
		nomi<<"----------------------------------------------------------------------------------------------"<<endl;
		nomi<<"|Nom |ID|  Cargo   | Sueldo|Aux.trans | Comisiones|Salud|pension|Horas extra|Total devengado|"<<endl; 
		nomi<<"----------------------------------------------------------------------------------------------"<<endl; 
		nomi<<"|"<<x.nom<<"|"<<x.Id<<" | Operario |"<<x.salario <<       "| 140.606  |      -     |"<<x.sd<<" |"<<x.pe<<"   |"<<x.ht<<"      |"<<x.st<<"        |"<<endl;
		nomi<<"----------------------------------------------------------------------------------------------"<<endl; 
		nomi<<"|"<<y.nom<<"|"<<y.Id<<" | vendedor |"<<y.salario <<       " |    -     |"<< y.s << "      |"<<y.sd<<" |"<<y.pn<<"   |"<<" -    " "|"<<y.st<<"        |"<<endl;
		nomi<<"----------------------------------------------------------------------------------------------"<<endl; 
		nomi<<"|"<<z.nom<<"|"<<z.Id<<" | gerente  |"<<z.salario <<       " |    -     |      -     |"<<z.sd<<"|"<<z.pn<<"  |"<<" -    " "|"<<z.st<<"        |"<<endl;
		nomi<<"----------------------------------------------------------------------------------------------"<<endl;
		cout<<"NOMINA.TXT generado"<<endl;     
	}
	else{
		cout<<"error, no se ha creado el archivo"<<endl;
	}
}
class  vocal{
	public:
		void vocales(Operario ,Vendedor ,Gerente);
};
void vocal::vocales(Operario x ,Vendedor y,Gerente z){
	 int cont,cont1,cont2;
    cont=cont1=cont2=0;
    int i = 0;
    while (x.nom[i] != '\0') {
        if (x.nom[i] == 'a' || x.nom[i] == 'e' || x.nom[i] == 'i' || x.nom[i] == 'o' || x.nom[i] == 'u' || x.nom[i] == 'A' || x.nom[i] == 'E' || x.nom[i] == 'I' || x.nom[i] == 'O' || x.nom[i] == 'U') {
            cont++;
        }
        i++;
    }
    i = 0;
    while (y.nom[i] != '\0') {
        if (y.nom[i] == 'a' || y.nom[i] == 'e' || y.nom[i] == 'i' || y.nom[i] == 'o' || y.nom[i] == 'u' || y.nom[i] == 'A' || y.nom[i] == 'E' || y.nom[i] == 'I' || y.nom[i] == 'O' || y.nom[i] == 'U') {
            cont1++;
        }
        i++;
    }
    i = 0;
    while (z.nom[i] != '\0') {
        if (z.nom[i] == 'a' || z.nom[i] == 'e' || z.nom[i] == 'i' || z.nom[i] == 'o' || z.nom[i] == 'u' || z.nom[i] == 'A' || z.nom[i] == 'E' || z.nom[i] == 'I' || z.nom[i] == 'O' || z.nom[i] == 'U') {
            cont2++;
        }
        i++;
    }
    if(cont>cont1&&cont>cont2){
    	cout<<"el nombre con mas vocales es: "<< x.nom<<endl;
    }
    else if(cont1>cont&&cont1>cont2){
    	cout<<"el nombre con mas vocales es: "<< y.nom<<endl;
    }
    else if(cont2>cont&&cont2>cont1){
    	cout<<"el nombre con mas vocales es: "<< z.nom<<endl;
    }
}
Operario::Operario(){
hs =ho = hon = hd= hdn =sd=pe=ht=0.0;
}
void Operario::Leer() {
    cout << "Digite su nombre señor operario: ";
    cin.getline(nom, 40);
    cout << "Digite su ID operario: ";
    cin >> Id;
    cout << "Digite su salario señor operario: ";
    cin >> salario;
    cin.ignore(); // Limpiar el búfer después de ingresar el salario
}
void Operario::Proceso() {
	int suma=0;
	int op,s,ops,h;
	cout<<"SR OPERARIO"<<endl;
    cout<<"1.vive cerca\n2.vive lejos"<<endl;
    cin>>ops;
    if(ops==1){
    
 	cout<<"señor  operario �trabajo horas extra?\n1.si\n2.no"<<endl;
 	cin>>op;
 	if(op==1){
 		int opc;
 		do{
 			cout<<"1.extra ordinaria\n2.extra nocturna ordinaria\n3.extra diurna dominical\n4.extra noctura dominical\n5.salir\n";
 			cin>>opc;
 			switch(opc){
 				case 1:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*1.25)/240;
 					cout<<hs;
 					ho=hs*h;
 					break;
 				case 2:	
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*1.75)/240;
 					hon=hs*h;
 					
 					break;
 				case 3:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*2.00)/240;
 					hd=hs*h;
 					
 					break;
 				case 4:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*2.5)/240;
 					hdn=hs*h;
 					break;
 			}
 			
 		}while(opc!=5);
 		suma+=h;
 		if(suma<48){
 		sd=salario*0.04;
 		pe=salario*0.04;
 		st=(salario+ho+hon+hd+hdn)-(sd+pe);
 		ht=ho+hon+hd+hdn;
 	}
 	else{
 		cout<<"horas extras incorrectas"<<endl;
 	}
 	}
 	else{
 		sd=salario*0.4;
 		pe=salario*0.4;
 		st=salario-(sd+pe);
 	}
 }
 else{
 	cout<<"se�or operario�trabajo horas extra?\n1.si\n2.no"<<endl;
 	cin>>op;
 	if(op==1){
 		int opc;
 		do{
 			cout<<"1.extra ordinaria\n2.extra nocturna ordinaria\n3.extra diurna dominical\n4.extra noctura dominical\n5.salir\n";
 			cin>>opc;
 			switch(opc){
 				case 1:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*1.25)/240;
 					ho=hs*h;
 					break;
 				case 2:	
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*1.75)/240;
 					hon=hs*h;
 					break;
 				case 3:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*2.00)/240;
 					hd=hs*h;
 					break;
 				case 4:
 					cout<<"¿cuantas horas extra trabajo?"<<endl;
 					cin>>h;
 					hs=(salario*2.5)/240;
 					hdn=hs*h;
 					break;
 			}
 			
 		}while(opc!=5);
 		suma+=h;
 		if(suma<48){
 		
 		sd=salario*0.04;
 			pe=salario*0.04;
 			st=(salario+ho+hon+hd+hdn+140600)-(sd+pe);
 			ht=ho+hon+hd+hdn;
 		}
 		else{
 			cout<<"horas extras incorrectas"<<endl;
 		}
 }
 else{
 			sd=salario*0.04;
 			pe=salario*0.04;
 			st=(salario+140600)-(sd+pe);
 }
}
}

void Operario::Imprimir() {
    cout<<" operario su nombre es: "<< nom<<endl;
    cout<<" operario su id es: "<< Id<<endl;
    cout<<" operario su sueldo es: "<< salario<<endl;
    cout<<" operario su salario total es de : "<< st<<endl;
}
Operario::~Operario(){
	cout<<"destruyendo datos"<<endl;
}

Vendedor::Vendedor(){
	st=pn=sd=0.0;
}
void Vendedor::Leer() {
    cout << "Digite su nombre señor vendedor: ";
    cin.getline(nom, 40);
    cout << "Digite su ID vendedor: ";
    cin >> Id;
    cout << "Digite su salario señor vendedor: ";
    cin >> salario;
    cin.ignore(); 
}
void Vendedor::Proceso() {
    int op,pre;
    cout<<"SR VENDEDOR"<<endl;
    cout<<"cuanto vendio al mes"<<endl;
    cin>>pre;
    if(pre>20000000&&pre<=50000000){
    		sd=salario*0.04;
    		pn=salario*0.04;
    		s=pre*0.013;
    		cout<<"comision"<<s<<endl;
    		st=(salario+s)-(sd+pn);
    }
    else if(pre>50000000){
    		sd=salario*0.04;
    		pn=salario*0.04;
    		s=pre*0.025;
    		st=(salario+s)-(sd+pn);
    }
    else{
  
    		sd=salario*0.04;
    		pn=salario*0.04;
    		st=(salario)-(sd+pn);
    	}
}  
void Vendedor::Imprimir() {
    cout<<"vendedor su nombre es: "<< nom<<endl;
    cout<<"vendedor su id es: "<< Id<<endl;
    cout<<"vendedor su sueldo es: "<< salario<<endl;
    cout<<"vendedor su salario total es de : "<< st<<endl;
}
Vendedor::~Vendedor(){
	cout<<"destruyendo datos"<<endl;
}
Gerente::Gerente(){
	st=sd=pn=0.0;
}
void Gerente::Leer() {
    cout << "Digite su nombre señor gerente: ";
    cin.getline(nom, 40);
    cout << "Digite su ID gerente: ";
    cin >> Id;
    cout << "Digite su salario señor gerente: ";
    cin >> salario;
    cin.ignore(); 
}

void Gerente::Proceso() {
	sd=pn=st=0.0;
	sd=salario*0.04;
	pn=salario*0.04;
    st=(salario)-(sd+pn);
}

void Gerente::Imprimir() {
    cout<<"Gerente su nombre es: "<< nom<<endl;
    cout<<"Gerente su id es: "<< Id<<endl;
    cout<<"Gerente su sueldo es: "<< salario<<endl;
    cout<<"Gerente su salario total es de : "<< st<<endl;
}
Gerente::~Gerente(){
	cout<<"destruyendo datos"<<endl;
}
int main() {
    Operario O;
    Vendedor V;
    Gerente G;
    Promedio p;
    archivo a;
    vocal v;
    O.Leer();
    V.Leer();
    G.Leer();
    O.Proceso();
    V.Proceso();
    G.Proceso();
    O.Imprimir();
    V.Imprimir();
    G.Imprimir();
    p.promedio(O,V,G);
    a.archi(O,V,G);
    v.vocales(O,V,G);
}

