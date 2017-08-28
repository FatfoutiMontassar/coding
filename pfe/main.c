#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weights[15] = {87,121,96,99,65,47,73,78,95,84,136,67,81,139,67};
    int value_found = 0 ;
    int idx[5] ;
    for(int i1 = 0 ; i1 < 15 && value_found==0 ; i1++){
        for(int i2 = i1+1 ; i2 < 15 && value_found==0 ; i2++){
            for(int i3 = i2+1 ; i3 < 15 && value_found==0 ; i3++){
                for(int i4 = i3+1 ; i4 < 15 && value_found==0 ; i4++){
                    for(int i5 = i4+1 ; i5 < 15 && value_found==0 ; i5++){

                        for(int msk = 0 ; msk < 32 && value_found==0 ; msk++){
                            ///printf("msk :: %d  :: ",msk) ;
                            int tempSum = 0 ;

                                if((msk&(1)) != 0){
                                    idx[0] = i1 ;
                                    tempSum += weights[i1] ;
                                    ///printf(" %d ",weights[i1]) ;
                                }else idx[0] = -1 ;

                                if((msk&(2)) != 0){
                                    idx[1] = i2 ;
                                    tempSum += weights[i2] ;
                                    ///printf(" %d ",weights[i2]) ;
                                }else idx[1] = -1 ;

                                if((msk&(4)) != 0){
                                    idx[2] = i3 ;
                                    tempSum += weights[i3] ;
                                    ///printf(" %d ",weights[i3]) ;
                                }else idx[2] = -1 ;

                                if((msk&(8)) != 0){
                                    idx[3] = i4 ;
                                    tempSum += weights[i4] ;
                                    ///printf(" %d ",weights[i4]) ;
                                }else idx[4] = -1 ;

                                if((msk&(16)) != 0){
                                    idx[4] = i5 ;
                                    tempSum += weights[i5] ;
                                    ///printf(" %d \n",weights[i5]) ;
                                }else idx[4] = -1 ;

                            ///printf("%d\n",tempSum) ;
                            if(tempSum>=498 && tempSum<=504){
                                value_found = 1 ;
                                ///printf("STOP!!\n");
                            }
                        }

                    }
                }
            }
        }
    }
    if(value_found == 0)printf("There's no possible combination !\n") ;
    else {
        printf("The Output is :\n");

        ///those are the indicies from the table
        ///you can replace idx[i] by weights[idx[i]] to obtain the values)

        int sum = 0 ;
        for(int i = 0 ; i < 5 ; i++){ printf("%d ",idx[i]) ; if(idx[i]>=0)sum += weights[idx[i]] ;}
        printf("\n");
        printf("And The Sum Is: %d\n",sum);
    }

    return 0;
}
