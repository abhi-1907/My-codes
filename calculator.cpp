#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;


int main()
{
    float n1,n2;
    int option1,option2;
    char ch;
    do
    {
    cout<<"Enter an operation\n1. Basic arithmetic operations\n2. Logarithmic operations\n3. Exponential operations\n4. Trigonometric operations\n5. Inverse trigonometric operations";
    cin>>option1;
    system("cls");
    switch(option1)
    {
        case 1:
        cout<<"You selected Arithmetic operation\n";
        cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder";
        cin>>option2;
        system("cls");
        switch(option2)
        {
            case 1:
            cout<<"You selection Addition";
            cout<<"\nEnter 1st number: ";
            cin>>n1;
            cout<<"\nEnter 2nd number: ";
            cin>>n2;
            cout<<"\nResult: "<<n1+n2;
            break;
            case 2:
            cout<<"You selected Subtraction";
            cout<<"Enter 1st number: ";
            cin>>n1;
            cout<<"\nEnter 2nd number: ";
            cin>>n2;
            cout<<"\nResult: "<<n1-n2;
            break;
            case 3:
            cout<<"You selected Multiplication";
            cout<<"Enter 1st number: ";
            cin>>n1;
            cout<<"\nEnter 2nd number: ";
            cin>>n2;
            cout<<"\nResult: "<<n1*n2;
            break;
            case 4:
            cout<<"You selected Division";
            cout<<"Enter 1st number: ";
            cin>>n1;
            cout<<"\nEnter 2nd number: ";
            cin>>n2;
            if(n2!=0)
            {
                cout<<"\nResult: "<<n1/n2;
            }
            else if(n2==0)
            {
                cout<<"Undefined!!!";
            }
            break;
            case 5:
            cout<<"You selected remainder";
            cout<<"Enter 1st number: ";
            cin>>n1;
            cout<<"\nEnter 2nd number: ";
            cin>>n2;
            if(n2!=0)
            {
                cout<<"\nResult: "<<remainder(n1,n2);
            }
            else if(n2==0)
            {
                cout<<"Undefined!!!";
            }
            break;
            default:
            cout<<"Enter a valid operation!!!";

        }
        break;
        case 2:
        cout<<"You selected logarithmic operation";
        cout<<"\n1.Natural logarithm\n2.Common logarithm\n3.Logarithm with other base";
        cin>>option2;
        system("cls");
        switch(option2)
        {
            case 1:
            cout<<"You selected natural logarithm";
            cout<<"\nEnter a number :";
            cin>>n1;
            cout<<"\nResult: "<<log(n1);
            break;
            case 2:
            cout<<"You selected common logarithm\nEnter a number :";
            cin>>n1;
            cout<<"\nResult: "<<log10(n1);
            break;
            case 3:
            cout<<"You selected logarithm with other base\nEnter the number : ";
            cin>>n1;
            cout<<"\nEnter the base : ";
            cin>>n2;
            cout<<"\nResult: "<<(log(n1)/log(n2));
            break;
            default:
            cout<<"Enter a valid operation!!!";
        }
        break;
        case 3:
        cout<<"You selected exponential operation\n1.Square\n2.Cube\n3.Square root\n4.Cube root\n5.Other power\n6.Power of 'e'";
        cin>>option2;
        system("cls");
        switch(option2)
        {
            case 1:
            cout<<"You selected square\nEnter a number : ";
            cin>>n1;
            cout<<"\nResult: "<<n1*n1;
            break;
            case 2:
            cout<<"you selected Cube\nEnter a number : ";
            cin>>n1;
            cout<<"\nResult: "<<n1*n1*n1;
            break;
            case 3:
            cout<<"You selected square root\nEnter a number : ";
            cin>>n1;
            cout<<"\nResult: "<<sqrt(n1);
            break;
            case 4:
            cout<<"You selected cube root\nEnter a number : ";
            cin>>n1;
            cout<<"\nResult: "<<pow(n1,1/3);
            break;
            case 5:
            cout<<"You selected Other power\nEnter a number : ";
            cin>>n1;
            cout<<"\nEnter the power: ";
            cin>>n2;
            cout<<"\nResult: "<<pow(n1,n2);
            break;
            case 6:
            cout<<"You selected power of 'e'\nEnter the power: ";
            cin>>n2;
            cout<<"\nResult: "<<exp(n2);
            break;
            default:
            cout<<"\nEnter a valid operation!!!";
        }
        break;
        case 4:
        cout<<"You selected Trigonometric operations\n1. sine\n2. cosine\n3. Tangent\n4. Cosecand\n5. Secant\n6. Cotangent";
        cin>>option2;
        system("cls");
        cout<<"\nEnter the angle: ";
        cin>>n1;
        cout<<"\n(1)Radian or (2)Degrees? : ";
        cin>>n2;
        if(n2==2)
        n1=(n1*3.14159)/180;
        system("cls");
        switch(option2)
        {
        case 1:
        cout<<"\nYou selected Sine\nResult: "<<sin(n1);
        break;
        case 2:
        cout<<"\nYou selected Cosine\nResult: "<<cos(n1);
        break;
        case 3:
        cout<<"\nYou selected Tangent\n Result: "<<tan(n1);
        break;
         case 4:
        cout<<"\nYou selected Cosecant\nResult: "<<1/sin(n1);
        break;
        case 5:
        cout<<"\nYou selected Secant\nResult: "<<1/cos(n1);
        break;
        case 6:
        cout<<"\nYou selected Cotangent\n Result: "<<1/tan(n1);
        break;
        default:
        cout<<"\nEnter a valid operation!!!";
        }
        break;
        case 5:
        cout<<"You selected inverse trigonnometric operations\n1.Inverse Sine\n2. nverse Cosine\n3. Inverse Tangent\n4. Inverse cosecant\n5. Inverse secant\n6. Inverse cotangent";
        cin>>option2;
        system("cls");
        switch(option2)
        {
            case 1:
            cout<<"\nYou selected Inverse sine";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<asin(n1);
            break;
            case 2:
            cout<<"\nYou selected Inverse cosine";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<acos(n1);
            break;
            case 3:
            cout<<"\nYou selected Inverse sine";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<atan(n1);
            break;
            case 4:
            cout<<"\nYou selected Inverse cosecant";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<asin(1/n1);
            break;
            case 5:
            cout<<"\nYou selected Inverse secant";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<acos(1/n1);
            break;
            case 6:
            cout<<"\nYou selected Inverse cotangent";
            cout<<"\nEnter a value: ";
            cin>>n1;
            cout<<"\nResult: "<<atan(1/n1);
            break;
            default:
            cout<<"Enter a valid operation!!!";
        }
        break;
        default:
        cout<<"\nEnter a valid operation!!!";
    }
    system("cls");
    cout<<"\nDo you wish to continue(y/n): ";
    cin>>ch;
    }while(ch=='y');
    return 0;
}