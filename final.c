

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

int tak;
char out[70];
struct info
{
    char email[20];
    char namee[20];
    char userid[20];
    char pass[20];
} s[100];
struct count
{
    int orderno;
} f1[100];
struct quantity
{
    char siz;
    int q1;
} s1[100];
struct add
{
    char area[20];
    char block_road[20];
    char houseNo[20];
    char apartment[20];
} a[100];
struct sum
{
    int sum1;
} m1;


void signup(void)
{

    int i,j;
    system("cls");
    printf("                       -------------------------------------------------------------------\n");
    printf("                                                  SIGN UP PLEASE\n");
    printf("                       -------------------------------------------------------------------\n\n\n\n");


    FILE*info;
    info=fopen("info.txt","a");
    if(info==NULL)
    {
        printf("error");
        exit(1);
    }
    for(i=0;; i++)
    {
        printf("\n\nEnter your email: ");
        scanf(" %[^\n]s",s[i].email);
        printf("Enter your full name: ");
        scanf(" %[^\n]s",s[i].namee);
        printf("Enter an username: ");
        scanf(" %[^\n]s",s[i].userid);
        printf("Enter a password: ");
        scanf(" %[^\n]s",s[i].pass);


        fwrite (&s[i],1, sizeof(struct info),info);
        break;
    }



    fclose(info);
    login();
}
void login(void)
{

    FILE*info;
    info=fopen("info.txt","r");
    int f1=0,f2=0;
    char username[70],pass1[70];
    struct info input;
    if (info == NULL)
    {
        printf("Error");
        exit (1);
    }

    system("cls");

    printf("                       -------------------------------------------------------------------\n");
    printf("                                                 LOGIN PORTAL\n");
    printf("                       -------------------------------------------------------------------\n");
    printf("\n\n\n\n\nLogin to your account-\n");

    printf("\n\nUsername: ");
    scanf(" %[^\n]s",username);
    printf("Password: ");
    scanf(" %[^\n]s",pass1);
    while(fread(&input, sizeof(struct info), 1, info))
        if(strcmp(input.userid,username)==0&&strcmp(pass1,input.pass)==0)
            f1=1;
    if(f1==0)
    {
        wlogin();
    }




    fclose(info);

}
void wlogin(void)
{

    FILE*info;
    info=fopen("info.txt","r");
    int f1=0,f2=0;
    char username[70],pass1[70];
    struct info input;
    if (info == NULL)
    {
        printf("Error");
        exit (1);
    }

    system("cls");
    printf("                       -------------------------------------------------------------------\n");
    printf("                                                  LOGIN PORTAL\n");
    printf("                       -------------------------------------------------------------------\n\n\n");
    printf("\n\n\a Wrong Username or password.\nTry Logging into your account again-\n");

    printf("\n\nUsername:");
    scanf(" %[^\n]s",username);
    printf("Password:");
    scanf(" %[^\n]s",pass1);
    while(fread(&input, sizeof(struct info), 1, info))
        if(strcmp(input.userid,username)==0&&strcmp(pass1,input.pass)==0)
            f1=1;
    if(f1==0)
    {
        printf("\n");
        printf("Wrong Username or Password. Type again....\n\n");
        wlogin();
    }




    fclose(info);

}
int mmenu()
{
    system("cls");
    printf("                  ***********\n");
    printf("                   Hery Cafe\n");
    printf("                  ***********\n");
    printf("\n\n\n\n\n");
    printf("          1. CUSTOMER SECTION  > \n\n          2. ABOUT US  > \n\n          3. Exit  > \n\n\n ");
    printf("\n");
    int n;
    scanf("%d", &n);
    if(n==1)
    {
        system("cls");
        int x;
        x=customer();
        return x;
    }
    else if(n==2)
    {
        about();
    }
    else if(n==3)
    {
        printf("\n\n\n                                    ....Thank you....\n\n");
        exit(1);
    }
    else
    {
        mmenu();
    }

}

int customer()
{
    int m,y;
    printf("                          -----------------------------------\n");
    printf("                                    Order Window\n\n\n");
    printf("                               -----------------------\n");
    printf("\n\n\n\n\n          1. Delivery  > \n\n          2. Takeaway  > \n\n          3. BACK TO MAIN MENU  >\n\n\n ");
    printf("\n");

    scanf("%d", &tak);
    if(tak==1)
    {
        m= oFood();
        system("cls");
        printf("\n\n\nTotal payable amount: ");
        return m;
    }
    else if(tak==2)
    {
        system("cls");
        int m;
        printf("\n\n\n\t\t                         Welcome to Takeaway Window\n");
        printf("\t\t                             ---------X--------\n\n\n\n\n");
        printf("Our available outlets:\n\n\n");
        printf("(1) Wari Outlet\t\   (2) Bashundhara Outlet\t   (3) Paltan Outlet\t   (4) Banani Outlet\t   (5) Mirpur Outlet\n\n");
        printf("\n\n\n\nPlease type your desired outlet location before we take you to our menu: ");
        scanf("%s",out);
        if(strcmp(out,"Wari")==0 || strcmp(out,"wari")==0 || strcmp(out,"Bashundhara")==0 || strcmp(out,"bashundhara")==0 || strcmp(out,"Paltan")==0 || strcmp(out,"paltan")==0 ||strcmp(out,"Banani")==0 || strcmp(out,"banani")==0 ||strcmp(out,"Mirpur")==0||strcmp(out,"mirpur")==0)
        {
            m= oFood();
            system("cls");
            printf("\n\n\nTotal payable amount: ");
            return m;
        }
        else
        {
            printf("\n\n\n\nYour given area name doesn't match our existing outlets. ");
            printf("\n\nPress (1) to go back to order window  >\n\n\nPress any other number to exit   >");
            scanf("%d",&y);
            if(y==1)
            {
                system("cls");
                customer();
            }
            else{
                exit(1);
            }

        }


    }
    else if(tak==3)
    {
        system("cls");
        mmenu();
    }
    else
    {
        customer();


    }

}

int oFood()
{
    int k,i,num;
    int sum=0;
    int q=1;
    char size,A,a,F,f;
    system("cls");
    printf("                                  -[MENU]-");
    printf("\n\n------------------------------------------------------------------------------\n");
    printf("Item Code# DESCRIPTION                    SIZE                     PRICE(tk) |\n");
    printf("------------------------------------------------------------------------------\n");
    printf("                                                                             |\n");
    printf("                             -Fast food -                                 |\n");
    printf("[1] ------- Burger --------------------- A.200 gm patty -----------  130     |\n");
    printf("                                         B.300 gm patty -----------  180     |\n");
    printf("                                                                             |\n");
    printf("[2] ------- Chicken Pizza -------------- A.12 inches --------------  750     |\n");
    printf("                                         B.16 inches -------------- 1250     |\n");
    printf("                                                                             |\n");
    printf("[3] ------- Fried Chicken -------------- A.1 pcs ------------------   85     |\n");
    printf("                                         B.4 pcs ------------------  320     |\n");
    printf("                                                                             |\n");
    printf("[4] ------- Grilled Chicken ------------ A.Half -------------------  140     |\n");
    printf("                                         B.Full -------------------  250     |\n");
    printf("                                                                             |\n");
    printf("[5] ------- Noodles -------------------- A.Half -------------------  130     |\n");
    printf("                                         B.Full -------------------  250     |\n");
    printf("                                                                             |\n");
    printf("[6] ------- Pasta ---------------------- A.Half -------------------  120     |\n");
    printf("                                         B.Full -------------------  240     |\n");
    printf("                                                                             |\n");
    printf("                                                                             |\n");
    printf("                          -Coffee\Tea items-                                 |\n");
    printf("[7] ------- Malai Cha ------------------ 250ml --------------------   70     |\n");
    printf("[8] ------- Cold Coffee ---------------- 250ml --------------------  100     |\n");
    printf("[9] ------- Cappuccino ----------------- 250ml --------------------  180     |\n");
    printf("                                                                             |\n");
    printf("                              -Beverage-                                     |\n");
    printf("[10] ------ Coke ---------------------- A.250 ml -----------------    20     |\n");
    printf("                                        B.500 ml -----------------    30     |\n");
    printf("------------------------------------------------------------------------------\n");
    printf("Press(11) to calculate Order\n");
    printf("Press(12) to view Order\n");
    printf("\nSelect your choice\n ");
    scanf("%d",&k);
    if(k>=1 && k<=10)
    {
        printf("\nEnter Quantity--> ");
        scanf("%d",&q);
    }
    if((k>=1 && k<=6)||k==10)
    {
        printf("\nEnter A/B to select Size--> ");
        scanf(" %c",&size);

    }

    if(k==1 && (size=='200'||size=='A'||size=='a'))
    {
        sum=q*130;

    }
    else if(k==1 && (size=='300'||size=='B'||size=='b'))
    {
        sum=q*180;

    }
    else if(k==2 && (size=='12'||size=='A'||size=='a'))
    {
        sum=q*750;

    }
    else if(k==2 && (size=='16'||size=='B'||size=='b'))
    {
        sum=q*1250;

    }
    else if(k==3 && (size=='1'||size=='A'||size=='a'))
    {
        sum=q*85;

    }
    else if(k==3 && (size=='4'||size=='B'||size=='b'))
    {
        sum=q*320;

    }
    else if(k==4 && (size=='A'||size=='a'))
    {
        sum=q*140;
    }

    else if(k==4 && (size=='B'||size=='b'))
    {
        sum=q*250;
    }
    else if(k==5 && (size=='A'||size=='a'))
    {
        sum=q*130;
    }
    else if(k==5 && (size=='B'||size=='b'))
    {
        sum=q*250;
    }
    else if(k==6 && (size=='A'||size=='a'))
    {
        sum=q*120;
    }
    else if(k==6 && (size=='B'||size=='b'))
    {
        sum=q*240;
    }
    else if(k==7)
    {
        sum=q*70;
    }
    else if(k==8)
    {
        sum=q*100;
    }
    else if(k==9)
    {
        sum=q*180;
    }
    else if(k==10 && (size=='A'||size=='a'))
    {
        sum=q*20;
    }

    else if(k==10 && (size=='B'||size=='b'))
    {
        sum=q*30;
    }
    else if(k==11)
        return 0;
    if(k>=1 && k<=10)
    {
        FILE *count;
        count=fopen("counter.txt","r");
        num=getw(count);

        fclose(count);

        f1[num].orderno=k;
        s1[num].siz=size;
        s1[num].q1=q;
        num=num+1;

        count=fopen("counter.txt","w");
        putw(num,count);
        fclose(count);

    }
    if(k>=1 && k<=10)
    {
        return sum=sum+ oFood();
    }
    else if(k==12)
    {

        viewo();
    }
    else
    {
        oFood();
    }




}

void contact ()
{
    int a;
    system("cls");
    printf("        ***                                                         \n");
    printf("       *   *  ***  *   * *****    *      ***  *****     *   *  ***  \n");
    printf("       *     *   * **  *   *     * *    *   *   *       *   * *     \n");
    printf("       *     *   * * * *   *    *****   *       *       *   *  ***  \n");
    printf("       *   * *   * *  **   *   *     *  *   *   *       *   *     * \n");
    printf("        ***   ***  *   *   *  *       *  ***    *        ***   ***   ");
    printf("\n\n\n\n       TELL US HOW\n       WE'RE DOING\n\n");
    printf("\n       Contact us here for questions regarding Hery's\n       complaints, refunds, and dislikes or likes about\n       your Hery's experience!\n\n");
    printf("\n       Need To Talk? Call Us.\n");
    printf("       ----------------------\n");
    printf("       | => 1-800-1234-123  |\n");
    printf("       ----------------------\n");
    printf("\n       You Can Also Mail Us.\n");
    printf("       --------------------------------\n");
    printf("       | => Hery.Cafe@email.com |\n");
    printf("       --------------------------------\n");
    printf("_______________________________________________________________________________________________________________________\n\n");
    printf("                                         (Hery Cafe Reserved All Rights.)\n\n\n");
    printf("\t\tType (1) to Login  >\n\n");
    printf("\t\tType (2) to Register a new account  >\n\n");
    printf("\t\tType any other number to Exit  >\n\n");
    scanf("%d",&a);
    if (a==1)
    {
        login();
    }
    else if(a==2)
    {
        signup();
    }

    else
    {

        exit(1);
    }
}



void about(void)
{
    char p;
    system("cls");
    printf("             **                                                       \n");
    printf("            *  *     *****   ***  *   * *****     *   *  ****             \n");
    printf("           *    *    *    * *   * *   *   *       *   * *             \n");
    printf("          ********   *****  *   * *   *   *       *   *  ****             \n");
    printf("         *        *  *    * *   * *   *   *       *   *      *           \n");
    printf("        *          * *****   ***   ***    *        ***   ****          ");
    printf("\n\n\n\n        At Hery Cafe, we're redefining fast food with our delicious and convenient\n        meals. We prioritize taste, quality, and freshness in every bite. Our menu offers a diverse\n        range of options to suit every palate, from juicy burgers to zesty wraps and refreshing salads.\n        With exceptional customer service and a commitment to giving back, we're here to create a\n        memorable dining experience. Join us and indulge in the perfect blend of flavor and\n        convenience at Hery's.\n\n");
    printf("___________________________________________________________________________________________________________________\n\n");

    printf("\t\t                                        -CREDITS-\n");
    printf("\t\t       ------------------------------------------------------------------------\n");
    printf("\t\t       |              Rahul Hasan Rony || Sayantan Saha Utsa                  |\n");
    printf("\t\t       ------------------------------------------------------------------------\n\n\n");
    printf("Press 1 to return-->");
    scanf("%d",&p);
    if(p==1)
    {

        mmenu();
    }
    else
    {

        about2();
    }
}
void about2(void)
{
    char p;
    system("cls");

    printf("                            **                                                       \n");
    printf("                           *  *     *****   ***  *   * *****     *   *  ****             \n");
    printf("                          *    *    *    * *   * *   *   *       *   * *             \n");
    printf("                         ********   *****  *   * *   *   *       *   *  ****             \n");
    printf("                        *        *  *    * *   * *   *   *       *   *      *           \n");
    printf("                       *          * *****   ***   ***    *        ***   ****          ");
    printf("\n\n\n\n        At Hery Cafe, we're redefining fast food with our delicious and convenient\n        meals. We prioritize taste, quality, and freshness in every bite. Our menu offers a diverse\n        range of options to suit every palate, from juicy burgers to zesty wraps and refreshing salads.\n        With exceptional customer service and a commitment to giving back, we're here to create a\n        memorable dining experience. Join us and indulge in the perfect blend of flavor and\n        convenience at Hery's.\n\n");
    printf("___________________________________________________________________________________________________________________________\n\n");

    printf("\t\t                                      -CREDITS-\n");
    printf("\t\t       ------------------------------------------------------------------------\n");
    printf("\t\t       |              Rahul Hasan Rony || Sayantan Saha Utsa                  |\n");
    printf("\t\t       ------------------------------------------------------------------------\n\n\n");
    printf("\n\n\a                                                   <--Invalid Input-->\n\n");
    printf("Press 1 to return-->");
    scanf("%d",&p);
    if(p==1)
    {

        mmenu();
    }
    else
    {

        about2();
    }
}

int viewo()
{

    system("cls");
    int l,j,i;
    FILE *count;
    count=fopen("counter.txt","r");
    j=getw(count);
    fclose(count);
    printf("Selected food items-\n\n\n");
    for(i=0; i<j; i++)
    {
        if(f1[i].orderno==1 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[1] ------- Burger ------------ quantity:%d -- 200 gm patty -----------------  %d bdt\n",s1[i].q1,130*s1[i].q1);
        }
        else if(f1[i].orderno==1 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[1] ------- Burger ------------ quantity:%d -- 300 gm patty -----------------  %d bdt\n",s1[i].q1,180*s1[i].q1);
        }
        else if(f1[i].orderno==2 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[2] ------- Chicken Pizza ---- quantity:%d --- 12 inches ----------------  %d bdt\n",s1[i].q1,750*s1[i].q1);
        }
        else if(f1[i].orderno==2 && s1[i].siz =='b' || s1[i].siz=='b')
        {
            printf("[2] ------- Chicken Pizza ---- quantity:%d --- 16 inches ----------------  %d bdt\n",s1[i].q1,1250*s1[i].q1);
        }
        else if(f1[i].orderno==3 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[3] ------- Fried Chicken ---- quantity:%d ---- 1 pcs------------------- %d bdt\n",s1[i].q1,85*s1[i].q1);
        }
        else if(f1[i].orderno==3 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[3] ------- Fried Chicken ---- quantity:%d ---- 4 pcs ------------------ %d bdt\n",s1[i].q1,320*s1[i].q1);
        }
        else if(f1[i].orderno==4 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[4] ------- Grilled Chicken -- quantity:%d ---- Half ------------------- %d bdt\n",s1[i].q1,140*s1[i].q1);
        }
        else if(f1[i].orderno==4 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[4] ------- Grilled Chicken -- quantity:%d ---- Full ------------------- %d bdt\n",s1[i].q1,250*s1[i].q1);
        }
        else if(f1[i].orderno==5 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[5] ------- Noodles ---------- quantity:%d ---- Half ------------------- %d bdt\n",s1[i].q1,130*s1[i].q1);
        }
        else if(f1[i].orderno==5 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[5] ------- Noodles ---------- quantity:%d ---- Full ------------------- %d bdt\n",s1[i].q1,250*s1[i].q1);
        }
        else if(f1[i].orderno==6 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[6] ------- Pasta ------------ quantity:%d ---- Half ------------------- %d bdt\n",s1[i].q1,120*s1[i].q1);
        }
        else if(f1[i].orderno==6 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[6] ------- Pasta ------------ quantity:%d ---- Full ------------------- %d bdt\n",s1[i].q1,240*s1[i].q1);
        }
        else if(f1[i].orderno==7 )
        {
            printf("[7] ------- Malai Cha -------- quantity:%d ---- 250ml ------------------ %d bdt\n",s1[i].q1,70*s1[i].q1);
        }
        else if(f1[i].orderno==8 )
        {
            printf("[8] ------- Cold Coffee ------ quantity:%d ---- 250ml ------------------ %d bdt\n",s1[i].q1,100*s1[i].q1);
        }
        else if(f1[i].orderno==9 )
        {
            printf("[9] ------- Cappuccino ------- quantity:%d ---- 250ml ------------------ %d bdt\n",s1[i].q1,180*s1[i].q1);
        }
        else if(f1[i].orderno==10 && s1[i].siz =='a' || s1[i].siz=='A')
        {
            printf("[10] ------ Coke ------------- quantity:%d ---- 250 ml ----------------- %d bdt\n",s1[i].q1,20*s1[i].q1);
        }
        else if(f1[i].orderno==10 && s1[i].siz =='b' || s1[i].siz=='B')
        {
            printf("[10] ------ Coke ------------- quantity:%d ---- 500 ml ----------------- %d bdt\n",s1[i].q1,300*s1[i].q1);
        }
    }
    printf("\n\n\n");
    printf("Press(1) confirm order->\n\n\n");
    printf("Press any other number to order again->\n");
    scanf("%d",&l);
    if(l==1)
    {
        return 0;
    }
    else
    {
        oFood();

    }
}

int main()
{
    int j=0;
    FILE *count;
    count=fopen("counter.txt","w");
    putw(j,count);
    fclose(count);
    int n,c,g,f,s,i,x,z;
    char p[50];
    char u[50]="dis1";
    char l[50]="dis2";
    char m[50]="dis3";
    float d,sum;
    printf("                              ***********************************************************************************\n");
    printf("                                                      Welcome to Hery Cafe\n");
    printf("                                  ***************************************************************************\n\n");
    printf("\n\n             Enter a number to select your option-\n\n");
    printf("             1.Log in  >\n\n");
    printf("             2.Create a new account  >\n\n");
    printf("             3.Contact us  >\n\n");
    printf("\n\n\n\n\n\n\n\n\n                                -----------------------------------------------------------------------------\n");
    scanf("%d",&n);
    if(n==1)
    {
        login();
    }
    else if(n==2)
    {
        signup();
    }
    else if(n==3)
    {
        contact();
    }
    else
    {
        printf("Invalid Input \n");
        exit(1);
    }

    int h;
    h=mmenu();
    printf("%d bdt",h);
    printf("\n\n\n\nDo you a promo code to get a discount?\n\n\n\t\tIf yes then press (1) to enter your promo code  > \n\n\t\tIf no then enter any number  >\n\n");
    scanf("%d",&x);

    if(x==1)
    {
        printf ("Enter promo code: ");
        scanf("%s",p);
        if(strcmp(p,u)==0)
        {
            printf("\n\nCongratulations! You have earned a 50 taka discount!\n");
            h=h-50;
        }
        else if(strcmp(p,l)==0)
        {
            printf("\n\nCongratulations! You have earned a 100 taka discount!\n");
            h=h-100;
        }
        else if(strcmp(p,m)==0)
        {
            printf("\n\nCongratulations! You have earned an 120 taka discount!\n");
            h=h-120;
        }
        else
        {
            printf("\n\n\n\n\nSorry! Not available now.");

        }
    }

    printf("\n\nPress (1) to continue  >\n\nPress any other number to cancel order  >\n");
    scanf("%d",&z);
    if(z==1)
    {

    }
    else
    {
        printf("Visit us again to order our luscious foods.\n\n\n\n\n");
        exit(1);
    }

    system("cls");
    printf("\n\n\n\n\t\tAmount Stands: %d BDT\n\n",h);
    if(tak==1)
    {
        printf("\t\tThe Delivery fee is 80 BDT");
        h=h+80;

        printf("\n\n\t\tYour final amount Stands: %d BDT",h);

        printf("\n\n\n\t\tEnter your Delivery address(within Dhaka District)  >\n\n\n",h);

        for(i=0;; i++)
        {
            printf("\n\nArea name:");
            scanf(" %[^\n]s",a[i].area);
            printf("\nBlock & Road no:");
            scanf(" %[^\n]s",a[i].block_road);
            printf("\nEnter your House no or name:");
            scanf(" %[^\n]s",a[i].houseNo);
            printf("\nEnter a Apartment or Floor no:");
            scanf(" %[^\n]s",a[i].apartment);
            break;
        }
        printf("\n\n\n\t\tPress(1) to confirm your order  >\n\n\t\tPress(2) to return back to Order Menu  >\n");
        scanf("%d",&s);
        if(s==1)
        {
            system("cls");
            printf("\n\n\n\n\t\tOrder placed. Your Order will be delivered at %s, %s, %s, %s .\nThank You.\n\n\n",a[i].houseNo,a[i].apartment,a[i].block_road,a[i].area);
        }
        else if(s==2)
        {
            system("cls");
            mmenu();
        }
    }
    else if(tak=2)
    {
        printf("\t\tYour food will be ready in 15-20 minutes. We expect your arrival at our %s outlet.\n\n\t\tThank you for ordering.\n\n\n\n\n\n\n\n\n\n\n\n",out);

    }

    return 0;
}
