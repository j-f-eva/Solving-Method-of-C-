#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
    int value;
    int weight;
    int model_no;
    double v_w;
};

bool weightCompare(Item x, Item y)
{
    if(x.v_w != y.v_w)
        return x.v_w > y.v_w;
}
int main()
{

    printf("Number of items: ") ;
    int num ;
    scanf("%d",&num);

    Item item[num];
    printf("\n") ;

    for(int i=0; i<num; i++)     //for taking inputs
    {
        Item x ;

        printf("Weight of item %d: ",i+1) ;
        scanf("%d",&x.weight);

        printf("Value of item %d: ",i+1);
        scanf("%d",&x.value) ;

        printf("\n") ;
        x.model_no = i+1;
        x.v_w = x.value / x.weight ;
        item[i] = x ;
    }

    sort(item,item+num,weightCompare);  ///item object sort

    printf("Maximum, capacity:  ");
    int weight_capacity, maxIncome=0 ;
    scanf("%d",&weight_capacity );


    printf("\n") ;

    for(int i=0; i<num ; i++)    ///find the max profit
    {
        Item x = item[i] ;


        if(weight_capacity >= x.weight)
        {
            printf("Item %d kg: %d\n", x.model_no,x.weight) ;
            weight_capacity -= x.weight;
            maxIncome += x.value ;
        }

        else if(weight_capacity >0)
        {
            int temp = weight_capacity * x.v_w ;
            printf("Item %d kg: %d\n", x.model_no, weight_capacity) ;
            weight_capacity = 0;
            maxIncome += temp ;
        }
         if(weight_capacity == 0)
            break ;
        }


    printf("\n Total value gained : %d\n", maxIncome );  ///print total value count

    return 0;

}

