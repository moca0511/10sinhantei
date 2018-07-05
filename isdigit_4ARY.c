#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ARY_ARY 5

long int tensum;
int inflag;//isdigit用
unsigned int in[ARY_ARY];

void tennumhan(void);

int main(void){

    printf("\n符号なし１０進数判断(入力有効数字　上%d桁)\n\n",ARY_ARY-1);
    
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
    for(f=1;f<ARY_ARY;f++){//桁の重み計算
        omosum=omosum*10;
        omomi[f]=omosum;
    }

    printf("input>:");//4mojiin
    scanf("%4s",incdash);
    keta=strlen(incdash);//長さ取得

    for(f=0;f<keta;f++){//逆順に並べ替え
        inc[f]=incdash[keta-1-f];
    }
    inc[keta]='\0';//文字列終了

    printf("keta=%d\n",keta);
    printf("in=%s\n",incdash);
    printf("inhan=%s\n",inc);

    for(f=0;f<keta;f++){//各要素を１０進数判定
        if(isdigit(inc[f])==0){//数字以外ならinflagおろす
            inflag=0;
        }
    }
    //ここで関数分割。
    

    if(inflag==1){//10進なら

    for(f=0;f<ARY_ARY;f++){//整数型に代入（asciicodeに変換）
        in[f]=inc[f];
    }    
    
    for(f=0;f<keta;f++){
        printf("\n%d桁目\n",f+1);
        printf("asciicode=%d\n",in[f]);
        printf("char=%c\n",in[f]);
        tennum=omomi[f]*(in[f]-48);//in char１→int 49→int 49-48=1→int 1*桁の重み=tennum
        printf("10sin=%d\n",tennum);
        tensum=tensum+tennum;//各桁を合計
        printf("sum=%d\n",tensum);
    }

    }else{
        printf("error!\n\n");
    }
    fflush( stdin );//４桁以上入力したときの繰り返しerror回避キーバッファクリア
    return;
}
 