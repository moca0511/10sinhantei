#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ARY_ARY 5

long int tensum;
int inflag;//isdigit�p
unsigned int in[ARY_ARY];

void tennumhan(void);

int main(void){

    printf("\n�����Ȃ��P�O�i�����f(���͗L�������@��%d��)\n\n",ARY_ARY-1);
    
    do{
        tennumhan();
    }
    while(inflag==0);

    tensum=tensum*tensum;
    printf("\nsum*sum=%d",tensum);
    
    return 0;
 }



void tennumhan(void)
{


    unsigned char inc[ARY_ARY],incdash[ARY_ARY];
    
    unsigned int omomi[ARY_ARY];
    int tennum,count,keta,f,omosum;
    omosum=1;
    tennum=0;
    tensum=0;
    omomi[0]=1;
    inflag=1;
    for(f=1;f<ARY_ARY;f++){//���̏d�݌v�Z
        omosum=omosum*10;
        omomi[f]=omosum;
    }

    printf("input>:");//4mojiin
    scanf("%4s",incdash);
    keta=strlen(incdash);//�����擾

    for(f=0;f<keta;f++){//�t���ɕ��בւ�
        inc[f]=incdash[keta-1-f];
    }
    inc[keta]='\0';//������I��

    printf("keta=%d\n",keta);
    printf("in=%s\n",incdash);
    printf("inhan=%s\n",inc);

    for(f=0;f<keta;f++){//�e�v�f���P�O�i������
        if(isdigit(inc[f])==0){//�����ȊO�Ȃ�inflag���낷
            inflag=0;
        }
    }
    //�����Ŋ֐������B
    

    if(inflag==1){//10�i�Ȃ�

    for(f=0;f<ARY_ARY;f++){//�����^�ɑ���iasciicode�ɕϊ��j
        in[f]=inc[f];
    }    
    
    for(f=0;f<keta;f++){
        printf("\n%d����\n",f+1);
        printf("asciicode=%d\n",in[f]);
        printf("char=%c\n",in[f]);
        tennum=omomi[f]*(in[f]-48);//in char�P��int 49��int 49-48=1��int 1*���̏d��=tennum
        printf("10sin=%d\n",tennum);
        tensum=tensum+tennum;//�e�������v
        printf("sum=%d\n",tensum);
    }

    }else{
        printf("error!\n\n");
    }
    fflush( stdin );//�S���ȏ���͂����Ƃ��̌J��Ԃ�error����L�[�o�b�t�@�N���A
    return;
}
 