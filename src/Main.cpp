#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Anggota{
    public:
    string nama;
    string noA;
    string bagian;

    Anggota(string nama, string noA, string bagian){
        Anggota::nama = nama;
        Anggota::noA = noA;
        Anggota::bagian = bagian;


    }

    string keString(){
        return "\n" +nama + " " + noA + " " + bagian;
    }
};

class dBase{
    public:
         ifstream in;
         ofstream out;
         string fileName;
  
    dBase(const char* fileName){
        dBase::fileName = fileName;
    }

    void saveData(Anggota data){

        dBase::out.open(dBase::fileName, ios::app);
        dBase::out << data.keString();


    }
    void showData(){
        string nama, noA, bagian;
        dBase::in.open(dBase::fileName, ios::in);
        int index = 1;

        while(!dBase::in.eof()){
            dBase::in >> nama;
            dBase::in >> noA;
            dBase::in >> bagian;
            cout << index++ << ". ";
            cout << nama << "\t";
            cout << noA << "\t";
            cout << bagian << endl;
        }
        dBase::in.close();

    }
};

int main(int argc, char const *argv[])
{
    string nama,noA,bagian;
    char lanjut;

    //system("cls");
    first:
    dBase database = ("data.txt");
    cout << "\nData Anggota : " << endl;
    database.showData();

    cout << "\nMasukan nama : ";
    cin >> nama;
    cout << "Masukan Nomor Anggota : ";
    cin >> noA;
    cout << "Masukan bagian : ";
    cin >> bagian;
    Anggota dataAnggota = Anggota(nama, noA, bagian);
    database.saveData(dataAnggota);
    

    cout << "\nLanjut menambahkan data?[y/n]> ";
    cin >> lanjut;

    if ((lanjut == 'y') || (lanjut == 'Y')){
        goto first;
    }else {
        cout << "exit program" << endl;
    }



    
    return 0;
}
