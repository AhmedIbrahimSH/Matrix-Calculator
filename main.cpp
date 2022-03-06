#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <string.h>

using namespace std;


// this project is used to take input from user as string and to convert it to integar and return the calculation that the user wants
// please enter matrix 1 on line 1 in the form of [a b c , d e f]
// please enter the operator that you want either +, -, * on line 2
// please enter matrix  on line 3 in the form of [a b c , d e f]

//  every space in the format of the input represents a column and each comma represent a row
// notice that any wrong input will output an error message so stick with the input format please THANK YOU!:)

//method to convert character array to string
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

//method to adjust the format of the input array of characters and return it as a string
string removeSpaces(char* a)
{
     string s = convertToString(a,strlen(a));
     while(s[s.length()-1]==' '){
         s.replace(0, s.length(), s.substr (0,s.length()-1));
     }
     while(s[0]==' '){
         s.replace(0, s.length(), s.substr (1,s.length()-1));
     }
     for(int i=0;i<s.length()-1;i++){
         if(s[i] == ' ' && s[i+1] == ' '){
             s.replace(i, 2, " ");
             i--;
         }
     }
     if(s[1]==' '&&s[0] == '['){
         s.replace(0,2,"[");
     }
     if(s[s.length()-2]==' ' && s[s.length()-1]==']'){
         s.replace(s.length()-2,2,"]");
     }
     for(int i=0;i<s.length()-1;i++){
         if(s[i] == ',' && s[i+1] != ' '){
             s.replace(i, 1, ", ");
             i++;
         }
     }
     for(int i=0;i<s.length()-1;i++){
         if(s[i] == ' ' && s[i+1] == ','){
             s.replace(i, 2, ",");
             i++;
         }
     }
     return s;
}


//output string in the right decimal places
void coutRightDecimalPlaces(long double number)
{
     if((int)number==number){
        cout << number;
    } else if((int)(number*10) == number*10){
        cout << setprecision(1) << fixed << number;
    } else cout << setprecision(2) << fixed  << number;
}


//main method

int main()
{
    //variables

    int rows1 = 0, columns1= 0;
    int rows2 = 0, columns2= 0;
    int sCount1 = 0, cCount1 = 0;
    int sCount2 = 0, cCount2 = 0;
    long double y = 9999.9999;
    long double z = -9999.9999;
    string matstr1[100][100];
    string matstr2[100][100];
    long double mat1[100][100];
    long double mat2[100][100];
    long double result[100][100];
    int tempCol = 0;
    char s[300];
    char s2[300];
    string x;
    bool isScalar1 = true;
    bool isScalar2 = true;

    //input

    cin.getline(s, 100, '\n');
    getline (cin, x);
    cin.getline(s2, 100, '\n');

    //checking if there is no input

    if(strlen(s) <1 || strlen(s2)<1){
        cout << "ERROR!";
        return 0;
    }

    //adjusting the input form

    strcpy(s, removeSpaces(s).c_str());
    strcpy(s2, removeSpaces(s2).c_str());


    for(int i=0;i<strlen(s);i++){
            if(s[i] == ' '){
                sCount1++;
            } else if(s[i] == ','){
                cCount1++;
            }
        }

        if(sCount1 > 100 || cCount1 > 100){
            cout << "ERROR!";
            return 0;
        }

        for(int i=0;i<strlen(s2);i++){
            if(s2[i] == ' '){
                sCount2++;
            } else if(s2[i] == ','){
                cCount2++;
            }
        }


        if(sCount2 > 100 || cCount2 > 100){
            cout << "ERROR!";
            return 0;
        }


    //checking operator

    if(x!="+" && x!="-" && x!="*"){
        cout << "ERROR!";
        return 0;
    }



    //checking if the first matrix is scalar

    for(int i=0;i<strlen(s);i++){

        if((s[i]<'0'||s[i]>'9') && s[i]!='.'){

            isScalar1 = false;
            break;
        }
    }

    //checking if the second matrix is scalar

    for(int i=0;i<strlen(s2);i++){

        if((s2[i]<'0'||s2[i]>'9') && s2[i] !='.'){

            isScalar2 = false;
            break;
        }
    }
    if(!isScalar1 && (s[0]!='[' || s[strlen(s)-1]!=']')){
        cout << "ERROR!";
        return 0;
    }
    if(!isScalar2 && (s2[0]!='[' || s2[strlen(s2)-1]!=']')){
        cout << "ERROR!";
        return 0;
    }
    //checking if both inputs are scalar

    if(isScalar1 && isScalar2){
        cout << "ERROR!";
        return 0;

    } else if(isScalar1){

        if(x != "*")
        {
            cout<<"ERROR!";
            return 0;
        }

        for(int i=0;i<strlen(s)-1;i++){
            if(s[i]==']' && s[i+1]!='\0'){
                cout << "ERROR!";
                return 0;
            }
        }

        string numString;
        int i=0;
        while (s[i] != '\0')
        {
            numString.append(1, s[i]);
            i++;
        }
        if(strlen(s2) <=2){
            cout<<"ERROR!";
            return 0;
        }
        if (s2[0] == '['){
        for(int i = 1; i < strlen(s2) ; i++){


            if ((s2[i] == ' ') ){

                if (s2[i - 1] == ',')
                    continue;

                else {
                    columns2++;
                    continue;
                }

            }
            else if (s2[i] == ',') {
                if(rows2 == 0){
                      tempCol = columns2;
                  }
                rows2++;
                if(columns2 != tempCol)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }

                columns2= 0;
                continue;
        }

            else if (s2[i] == ']') {
                if(columns2 != tempCol && rows2!=0)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }
                break;
        }
            else
        {


                matstr2[rows2][columns2].append(1,s2[i]);


                continue;

        }


    }





    for (int i = 0;i <= rows2;i++) {
        for (int j = 0;j <= columns2;j++) {
            mat2[i][j] = stold(matstr2[i][j]);
            if(mat2[i][j] > y || mat2[i][j] < z){
                cout<<"ERROR!";
                return 0;
            }
        }
    }

        long double numDouble = stold(numString);
        cout << "[";
        for(int i=0;i<=rows2;i++){
            if(i!=0){
                cout << ", ";
            }
            for(int j=0;j<=columns2;j++){
                result[i][j] = numDouble * mat2[i][j];
                if(j!=columns2){
                    coutRightDecimalPlaces(result[i][j]);
                    cout<<" ";
                } else {
                    coutRightDecimalPlaces(result[i][j]);
                }
            }
        }
        cout << "]";
    }
    } else if(isScalar2){

        if( x != "*")
        {
            cout<<"ERROR!";
            return 0;
        }

        for(int i=0;i<strlen(s2)-1;i++){
            if(s2[i]==']' && s2[i+1]!='\0'){
                cout << "ERROR!";
                return 0;
            }
        }

        string numString;
        int i=0;
        while (s2[i] != '\0')
        {
            numString.append(1, s2[i]);
            i++;
        }
        if(strlen(s) <=2){
            cout<<"ERROR!";
            return 0;
        }
        if (s[0] == '['){
        for(int i = 1; i < strlen(s) ; i++){


            if ((s[i] == ' ')){

                if (s[i - 1] == ',')
                    continue;

                else {
                    columns1++;
                    continue;
                }

            }


            else if (s[i] == ',') {
                  if(rows1 == 0){
                      tempCol = columns1;
                  }
                rows1++;
                if(columns1 != tempCol)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }


                columns1= 0;
                continue;
        }


            else if (s[i] == ']') {
                 if(columns1 != tempCol && rows1!=0)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }
                break;
        }
            else
        {


                matstr1[rows1][columns1].append(1,s[i]);


                continue;

        }




    }
    for (int i = 0;i <= rows1;i++) {
        for (int j = 0;j <= columns1;j++) {
            mat1[i][j] = stold(matstr1[i][j]);
            if(mat1[i][j] > y || mat1[i][j] < z){
                cout<<"ERROR!";
                return 0;
            }
        }
    }

        long double numDouble = stold(numString);
        cout << "[";
        for(int i=0;i<=rows1;i++){
            if(i!=0){
                cout << ", ";
            }
            for(int j=0;j<=columns1;j++){
                result[i][j] = numDouble * mat1[i][j];
                if(j!=columns1){
                    coutRightDecimalPlaces(result[i][j]);
                    cout<<" ";
                } else {
                    coutRightDecimalPlaces(result[i][j]);
                }
            }
        }
        cout << "]";
    }
    } else {
        if(strlen(s2) <=2){
            cout<<"ERROR!";
            return 0;
        }
        if(strlen(s) <=2){
            cout<<"ERROR!";
            return 0;
        }
        for(int i=0;i<strlen(s);i++){
            if(s[i] == ' '){
                sCount1++;
            } else if(s[i] == ','){
                cCount1++;
            }
        }
        for(int i=0;i<strlen(s2);i++){
            if(s2[i] == ' '){
                sCount2++;
            } else if(s2[i] == ','){
                cCount2++;
            }
        }

        for(int i=0;i<strlen(s);i++){

            if((s[i]<'0'||s[i]>'9') && s[i] !=' ' && s[i] !=',' && s[i] !='[' && s[i] !=']' && s[i]!='.' && s[i]!='-'){

                cout << "ERROR!"<<endl;
                return 0;
            }
        }
        for(int i=0;i<strlen(s2);i++){
            if((s2[i]<'0'||s2[i]>'9') && s2[i] !=' ' && s2[i] !=',' && s2[i] !='[' && s2[i] !=']' && s2[i]!='.' && s2[i]!='-'){
                cout << "ERROR!"<<endl;
                return 0;
            }
        }
        for(int i = 1; i < strlen(s) ; i++){


            if ((s[i] == ' ')){

                if (s[i - 1] == ',')
                    continue;

                else {
                    columns1++;
                    continue;
                }

            }


            else if (s[i] == ',') {
                  if(rows1 == 0){
                      tempCol = columns1;
                  }
                rows1++;
                if(columns1 != tempCol)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }


                columns1= 0;
                continue;
        }


            else if (s[i] == ']') {
                 if(columns1 != tempCol && rows1!=0)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }
                break;
        }
            else
        {


                matstr1[rows1][columns1].append(1,s[i]);


                continue;

        }




    }

        for(int i = 1; i < strlen(s2) ; i++){


            if ((s2[i] == ' ') ){

                if (s2[i - 1] == ',')
                    continue;

                else {
                    columns2++;
                    continue;
                }

            }
            else if (s2[i] == ',') {
                if(rows2 == 0){
                      tempCol = columns2;
                  }
                rows2++;
                if(columns2 != tempCol)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }

                columns2= 0;
                continue;
        }

            else if (s2[i] == ']') {
                if(columns2 != tempCol && rows2!=0)
                {
                cout<<"ERROR!"<<endl;
                return 0;
                }
                break;
        }
            else
        {


                matstr2[rows2][columns2].append(1,s2[i]);


                continue;

        }




    }

        if(x != "*" && (sCount1!=sCount2 || cCount1!=cCount2)){
            cout << "ERROR!" << endl;
            return 0;
        }
        if(x == "*" && rows2!=columns1){
            cout << "ERROR!" << endl;
            return 0;
        }

        for (int i = 0;i <= rows1;i++) {
            for (int j = 0;j <= columns1;j++) {
                mat1[i][j] = stold(matstr1[i][j]);
                if(mat1[i][j] > y || mat1[i][j] < z){
                    cout<<"ERROR!";
                    return 0;
            }
            }
        }

        for (int i = 0;i <= rows2;i++) {
            for (int j = 0;j <= columns2;j++) {
                mat2[i][j] = stold(matstr2[i][j]);
                if(mat2[i][j] > y || mat2[i][j] < z){
                    cout<<"ERROR!";
                    return 0;
            }
            }
        }





        if(x=="*"){
            cout << "[";
            for(int i=0;i<=rows1;i++) {
                if(i!=0){
                    cout << ", ";
                }
                for(int j=0;j<=columns2;j++)  {
                    result[i][j]=0;
                    for(int k=0;k<=columns1;k++){
                        result[i][j]+=mat1[i][k]*mat2[k][j];
                    }

                    if(j!=columns2){
                        coutRightDecimalPlaces(result[i][j]);
                        cout<<" ";

                    } else {
                        coutRightDecimalPlaces(result[i][j]);
                    }
                }
            }
            cout << "]";

        } else {
            cout << "[";
        for(int i=0;i<=rows1;i++){
            if(i!=0){
                cout << ", ";
            }
            for(int j=0;j<=columns1;j++){
                if(x == "+"){
                    result[i][j] = mat1[i][j]+mat2[i][j];
                } else if(x == "-"){
                    result[i][j] = mat1[i][j]-mat2[i][j];
                }
                if(j!=columns1){
                    coutRightDecimalPlaces(result[i][j]);
                    cout<<" ";

                } else {
                    coutRightDecimalPlaces(result[i][j]);
                }

            }
        }
            cout << "]" << endl;
        }

}

    return 0;
}
