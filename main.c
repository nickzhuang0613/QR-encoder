#include <stdio.h>
#include <stdlib.h>
#include "definition.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <string.h>

unsigned int calalign_n(int ver) //����У��ͼ������ͬʱΪУ��ͼ�����긳ֵ
{
    if(ver==1) return 0;
    if(ver>1&&ver<=6) return 1;
    if(ver>6&&ver<=13) return 6;
    if(ver>13&&ver<=20) return 13;
    if(ver>20&&ver<=27) return 22;
    if(ver>27&&ver<=34) return 33;
    if(ver>34&&ver<=40) return 46;
    else return -1;
}
void getalign_coord(Qrcodeinfo* qrcode,int ver)
{
    if(ver>=1) qrcode->align_coord[0]=6;
    if(ver>1&&ver<=6) qrcode->align_coord[1]=10+4*ver;
    if(ver>=7&&ver<=13)
    {
        qrcode->align_coord[1]=8+2*ver;
        qrcode->align_coord[2]=10+4*ver;
    }
    if(ver>=14&&ver<=16)
    {
        qrcode->align_coord[1]=26;
        qrcode->align_coord[2]=46+2*(ver-14);
        qrcode->align_coord[3]=66+4*(ver-14);
    }
    if(ver>=17&&ver<=19)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=54+2*(ver-17);
        qrcode->align_coord[3]=78+4*(ver-17);
    }
    if(ver==20)
    {
        qrcode->align_coord[1]=34;
        qrcode->align_coord[2]=62;
        qrcode->align_coord[3]=90;
    }
    if(ver>=21&&ver<=27)
        qrcode->align_coord[4]=94+4*(ver-21);
    if(ver==21)
    {
        qrcode->align_coord[1]=28;
        qrcode->align_coord[2]=50;
        qrcode->align_coord[3]=72;
    }
    if(ver==22)
    {
        qrcode->align_coord[1]=26;
        qrcode->align_coord[2]=50;
        qrcode->align_coord[3]=74;
    }
    if(ver==23)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=78;
    }
    if(ver==24)
    {
        qrcode->align_coord[1]=28;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=80;
    }
    if(ver==25)
    {
        qrcode->align_coord[1]=32;
        qrcode->align_coord[2]=58;
        qrcode->align_coord[3]=84;
    }
    if(ver==26)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=58;
        qrcode->align_coord[3]=86;
    }
    if(ver==27)
    {
        qrcode->align_coord[1]=34;
        qrcode->align_coord[2]=62;
        qrcode->align_coord[3]=90;
    }
    if(ver>=28&&ver<=34)
        qrcode->align_coord[5]=122+4*(ver-28);
    if(ver==28)
    {
        qrcode->align_coord[1]=26;
        qrcode->align_coord[2]=50;
        qrcode->align_coord[3]=74;
        qrcode->align_coord[4]=98;
    }
    if(ver==29)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=78;
        qrcode->align_coord[4]=102;
    }
    if(ver==30)
    {
        qrcode->align_coord[1]=26;
        qrcode->align_coord[2]=52;
        qrcode->align_coord[3]=78;
        qrcode->align_coord[4]=104;
    }
    if(ver==31)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=56;
        qrcode->align_coord[3]=82;
        qrcode->align_coord[4]=108;
    }
    if(ver==32)
    {
        qrcode->align_coord[1]=34;
        qrcode->align_coord[2]=60;
        qrcode->align_coord[3]=86;
        qrcode->align_coord[4]=112;
    }
    if(ver==33)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=58;
        qrcode->align_coord[3]=86;
        qrcode->align_coord[4]=114;
    }
    if(ver==34)
    {
        qrcode->align_coord[1]=34;
        qrcode->align_coord[2]=62;
        qrcode->align_coord[3]=90;
        qrcode->align_coord[4]=118;
    }
    if(ver>=35&&ver<=40)
        qrcode->align_coord[6]=150+4*(ver-35);
    if(ver==35)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=78;
        qrcode->align_coord[4]=102;
        qrcode->align_coord[5]=126;
        qrcode->align_coord[6]=150+4*(ver-35);
    }
    if(ver==36)
    {
        qrcode->align_coord[1]=24;
        qrcode->align_coord[2]=56;
        qrcode->align_coord[3]=82;
        qrcode->align_coord[4]=108;
        qrcode->align_coord[5]=128;
    }
    if(ver==37)
    {
        qrcode->align_coord[1]=28;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=80;
        qrcode->align_coord[4]=106;
        qrcode->align_coord[5]=132;
    }
    if(ver==38)
    {
        qrcode->align_coord[1]=32;
        qrcode->align_coord[2]=58;
        qrcode->align_coord[3]=84;
        qrcode->align_coord[4]=110;
        qrcode->align_coord[5]=136;
    }
    if(ver==39)
    {
        qrcode->align_coord[1]=26;
        qrcode->align_coord[2]=54;
        qrcode->align_coord[3]=82;
        qrcode->align_coord[4]=110;
        qrcode->align_coord[5]=138;
    }
    if(ver==40)
    {
        qrcode->align_coord[1]=30;
        qrcode->align_coord[2]=58;
        qrcode->align_coord[3]=86;
        qrcode->align_coord[4]=114;
        qrcode->align_coord[5]=142;
    }


    if(ver>MAXVERSION)
    {printf("�����汾���ƣ�Ŀǰ��֧��ǰ14���汾\n");return;}
}
void QRinit(Qrcodeinfo* qrcode,int ver) //��ָ���汾�����ɸö�ά���������Ϣ
{
    qrcode->ver=ver;
    if(ver>MAXVERSION)
        {printf("�汾�������ƣ�Ŀǰ��֧��ǰ14���汾\n");return;}
    qrcode->length=17+4*ver;
    qrcode->align_n=calalign_n(ver);
    getalign_coord(qrcode,ver);
    if(ver==1) qrcode->funcn=202;
    else qrcode->funcn=180+25*qrcode->align_n+2*qrcode->length-10*sqrt(3+qrcode->align_n);
    qrcode->formatn=ver<=6? 31:67;
    qrcode->datan=qrcode->length*qrcode->length-qrcode->funcn-qrcode->formatn;
    qrcode->coden=qrcode->datan/8;
    qrcode->ecodata=econfig[ver-1];
    qrcode->msgn=(qrcode->datan-qrcode->ecodata.ecoden*8)/8*8; //���ձ�׼����Ϣλ������������ӦΪ8�ı���
    qrcode->msgcode=qrcode->msgn/8;
    qrcode->remainbit=qrcode->datan%8;
}
unsigned int getmsgn(unsigned int ver)
{
    unsigned int funcn,formatn,datan,msgn;
    formatn=ver<=6? 31:67;
    if(ver==1) funcn=202;
    else funcn=180+25*calalign_n(ver)+2*(17+4*ver)-10*sqrt(3+calalign_n(ver));
    datan=(17+4*ver)*(17+4*ver)-funcn-formatn;
    msgn=(datan-econfig[ver-1].ecoden*8)/8*8; //���ձ�׼����Ϣλ������������ӦΪ8�ı���
    return msgn;
}
unsigned int getdatan(unsigned int ver)
{
    unsigned int funcn,formatn,datan;
    formatn=ver<=6? 31:67;
    if(ver==1) funcn=202;
    else funcn=180+25*calalign_n(ver)+2*(17+4*ver)-10*sqrt(3+calalign_n(ver));
    datan=(17+4*ver)*(17+4*ver)-funcn-formatn;
    return datan;
}
//�����������ͣ�����ֵ˵����0�����֣�1��8λ�ֽڣ�-1���ݲ�֧��
int str_analysis(char* text)
{
    int num=1;
    for(;*text!=0;text++) {if(!(OFNUMBER(text))) num=0;}
    if(num==1) return 0;
    else return 1;
}
int numcal(int n) //����ģʽ�������ָ�����������Ķ���������λ��
{
    int coden,leftn,finn;
    coden=n/3;
    leftn=n%3;
    if(leftn==0) finn=coden*10;
    if(leftn==1) finn=coden*10+4;
    if(leftn==2) finn=coden*10+7;
    if(n<=235) finn+=4+10; //<288
    else if(n<=1425) finn+=4+12;         //�Ӱ汾10��ʼ���ַ�����ָʾ����λ����12������10
    else finn+=4+14;
    return finn;
}
int asciical(int n)//��λ�ֽ�ģʽ����ascii�������������Ķ���������λ��
{
    int finn=8*n;
    if(n<=98) finn+=4+8;
    else finn+=4+16;
    return finn;
}
int ver_determine(char* text,int mode) //ȷ���汾
{
    unsigned int ver,len=strlen(text);
    unsigned int num,msgn;
    if(mode==NUMBERMODE) num=numcal(len);
    else if(mode==ASCIIMODE) num=asciical(len);
    else {printf("����ʶ��Ĵ���\n");num=0;return -1;}
        for(ver=1;ver<=MAXVERSION;ver++)
            {
                msgn=getmsgn(ver);
                if(msgn<num)
                {
                    if(ver==MAXVERSION) return -1;
                    msgn=getmsgn(ver+1);
                    if(msgn>=num)
                        return (ver+1);
                }
                else if(ver==1) return 1;
            }
    return -2;
}
char* itoa(int,char*,int);
void bin_init(int ver,int mode,char* bin,int n) //�ڶ�����λ�������ģʽָʾ���ͼ���ָʾ��
{
    char *data,temp[16],*p;int len,reallen;//data:
    strcat(bin,modeindic[mode]);

    itoa(n,temp,2); //���ַ���ת��Ϊ������
    reallen=strlen(temp);
    if(ver>=1&&ver<=9) {len=11;if(mode==ASCIIMODE) len=9;}//������
    if(ver>=10&&ver<=26) {len=13;if(mode==ASCIIMODE) len=17;}
    if(ver>=27&&ver<=40) {len=15;if(mode==ASCIIMODE) len=17;}
    data=(char*)malloc(len);
    for(p=data;p<data+len-reallen-1;p++) *p='0';
    strcpy(p,temp);//p��ʱָ��data�����һλ���
    strcat(bin,data);
    free(data);
}
char (*num_strdivide(char* text))[4] //��ԭ�ı����飬����һ����ָ��
{
    static char part[200][4];
    char (*p)[4]=part,*q=text;
    unsigned int j=0;
    for(;*q;j++) {if(j!=0&&j%3==0) p++; (*p)[j%3]=*q++;}
    return part;
}
//������2
void numtobin(char (*part)[4],char* bin) //�������������������
{
    int dint;
    unsigned int l,len;
    char temp[12],*data,*p;
    for(;(*part)[0];part++)
    {
        dint=atoi(*part);
        itoa(dint,temp,2);
        l=strlen(temp);
        if(strlen(*part)==2) len=8;
        else if(strlen(*part)==1) len=5;
        else len=11;
        data=(char*)malloc(len);
        for(p=data;p<data+len-l-1;p++) *p='0';  //data��ǰ��len-l-1��0
        strcpy(p,temp);
        strcat(bin,data);
        free(data);
    }
}
void asciitobin(char* text,char* bin)
{
    char* p,*data;unsigned int len=9,reallen;
    char temp[10];
    for(;*text;text++)
    {
        itoa(*text,temp,2);
        reallen=strlen(temp);
        data=(char*)malloc(len);
        for(p=data;p<data+len-reallen-1;p++) *p='0';  //data��ǰ��len-l-1��0
        strcpy(p,temp);
        strcat(bin,data);
        free(data);
    }
}
void terminator(Qrcodeinfo* qrcode,char* bin)
{
    int remainbit=qrcode->msgn-strlen(bin),i;
    if(remainbit<4)
        for(i=1;i<=remainbit;i++) strcat(bin,"0");
    else for(i=1;i<=4;i++) strcat(bin,"0");
}
CodeArray tomsgcode(Qrcodeinfo* qrcode,char* bin)
{
    int num=qrcode->msgcode;
    CodeArray msgcode=(CodeArray)malloc(num*9);
    CodeArray p=msgcode;
    unsigned int j=0;
    for(;*bin;j++) {if(j!=0&&j%8==0) {(*p)[8]=0;p++;} (*p)[j%8]=*bin++;}
    if(j%8!=0) for(;j%8;j++) (*p)[j%8]='0';
    for(p=p+1,j=0;p<=msgcode+num-1;p++,j++) strcpy(*p,filler[j%2]);
    return msgcode;
}
int codetonum(char* str)
{
    int sum=0;int i;
    for(i=0;i<=7;i++)
        sum+=(str[i]-48)*pow(2,7-i);
    return sum; //sum��ȡֵΪ0,1,...,255.����0����������a���ݱ�ʾ
}
int GFadd(int a,int b)
{
    int c=a^b;
    return c;
}
int GFmulti(int a, int b)
{
    if(a==0||b==0) return 0;
    int poa=powerof(a),pob=powerof(b);
    int poc=poa+pob;
    return alphato(poc);
}
int GFmultialphato(int a, int b)
{
    if(a==0) return 0;
    int poa=powerof(a);
    poa+=b;
    return alphato(poa);
}
int GFdivide(int a, int b)
{
    if(a==0) return 0;
    int poa=powerof(a),pob=powerof(b);
    int poc=poa>pob?(poa-pob):(poa-pob+255);
    return alphato(poc);
}
void PolyMultiply(int N,int* Const,int (*Ecoe)[N],int i,int delta)
{
    int n,poConst,poEcoe;
    poConst=powerof(Const[i])+delta;
    Const[i]=alphato(poConst);
    for(n=0;n<=N-1;n++)
    {
        if(Ecoe[i][n]!=0)
        {poEcoe=powerof(Ecoe[i][n])+delta;
        Ecoe[i][n]=alphato(poEcoe);}
        else Ecoe[i][n]=0;
    }
}
void PolyAdd(int N,int* Const,int (*Ecoe)[N],int i,int j) //����i+1��ʽ������j+1��ʽ�ӣ������浽��i+1��ʽ����
{
    int n;
    Const[i]=Const[i]^Const[j];
    for(n=0;n<=N-1;n++)
        Ecoe[i][n]=Ecoe[i][n]^Ecoe[j][n];
}
void RowExchange(int N,int* Const,int (*Ecoe)[N],int i,int j)
{
    int temp,n;
    for(n=0;n<=N-1;n++)
        {temp=Ecoe[i][n];Ecoe[i][n]=Ecoe[j][n];Ecoe[j][n]=temp;}
    temp=Const[i];Const[i]=Const[j];Const[j]=temp;
}
void RootSubstract(int N,int* Const,int (*Ecoe)[N],int root,int n)//n����n����
{
    int *delta=(int*)malloc(N*sizeof(int)),i;
    for(i=0;i<=N-1;i++)
    {
        delta[i]=GFmulti(Ecoe[i][n-1],root);
        Const[i]=GFadd(delta[i],Const[i]);
    }
}
void PrintEQA(int N, int* Const,int (*Ecoe)[N],int n)//nΪ��ǰ����
{
    printf("--------------����--------------\n");
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        printf("Const:%d Ecoe:",Const[i]);
        for(j=0;j<=n-1;j++)
    {
        printf("%d ",Ecoe[i][j]);
    }
    printf("\n");
    }
    printf("--------------------------------\n");
}
/*int* GaussEliminate(int N,int* Const,int (*Ecoe)[N])  //��˹��Ԫ
{
    int* Enum=(int*)malloc(N*sizeof(int)),*pN=&N;
    int i=0,j=0,k=0,m,delta,mark,sign=0,n=N;
    //sign��ʶ�Ƿ�����Ԫ
    //i:���ڴ����(i+1)������ m:���ڼ���m+1��Ԫ�Ƿ���ȥ
    for(;;)
    {
        sign=0;
        for(m=0;;m++)
        {
            if(n==1) {sign=1;break;}
            if(Ecoe[i][m]==0) {if(m!=n-2) continue; else {sign=1;break;}}
            else if(m>=i) {i++;break;} //���е�Ԫ������
            //���л��������Ԫ
            for(k=0;k<i;k++)
            {
                mark=0;//��¼��(m+1)λǰ���Ƿ��з�����
                for(j=0;j<m;j++) //���(i+1)�����̱Ƚϵķ��̣���(m+1)λ��ǰ���붼�Ѿ���Ԫ
                if(Ecoe[k][j]!=0) {mark=1;break;}
                if(mark==1||Ecoe[k][m]==0) {if(k==i-1) {printf("�ⷽ�̴���m=%d k=%d i=%d\n",m,k,i);} else continue;} //�з�����,���ߵ�(m+1)λ��Ϊ��Ͳ���Ҫ��
                printf("m=%d k=%d i=%d sign=%d N=%d\n",m,k,i,sign,N);
                delta=(powerof(Ecoe[k][m])-powerof(Ecoe[i][m]))>=0?(powerof(Ecoe[k][m])-powerof(Ecoe[i][m])):(powerof(Ecoe[k][m])-powerof(Ecoe[i][m])+255);
                PolyMultiply(N,Const,Ecoe,i,delta);
                //printf("delta=%d After Multiply:\n",delta);
                //PrintEQA(N,Const,Ecoe,n);
                //system("pause");
                PolyAdd(N,Const,Ecoe,i,k);
                //printf("After Add:\n");
                //PrintEQA(N,Const,Ecoe,n);//system("pause");
                break;//����Ԫ���������ѭ��
            }
            if(Ecoe[i][m]==0) if(m==n-2){sign=1;break;}
        }
        if(sign==1) //������һ�����Ѿ�����
        {
            //printf("��Ԫǰ��\n");
            //PrintEQA(N,Const,Ecoe,n);system("pause");
            Enum[n-1]=GFdivide(Const[i],Ecoe[i][n-1]);
            //Enum[n-1]=alphato((powerof(Const[i]-powerof(Ecoe[i][n-1])))>=0?(powerof(Const[i]-powerof(Ecoe[i][n-1]))):(powerof(Const[i]-powerof(Ecoe[i][n-1]))+255));
            RowExchange(N,Const,Ecoe,n-1,i);
            RootSubstract(N,Const,Ecoe,Enum[n-1],n);
            //printf("����Ԫ��\n");
            //PrintEQA(N,Const,Ecoe,n);system("pause");
            //printf("N--��֮��n=%d\n",n-1);
            n--;
            //PrintEQA(N,Const,Ecoe,n);system("pause");
            if(n==0) break;
            i=0;
        }
    }
    return Enum;
}*/
int* GaussEliminate(int N,int* Const,int (*Ecoe)[N])
{
    int i,j,k,diagonal;
    int *errors=(int*)malloc(N*sizeof(int));
    int *errors2=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
        errors[i]=Const[i];
    for(i=0;i<N;i++)
    {
        diagonal=Ecoe[i][i];
        for(j=0;j<N;j++)
            Ecoe[i][j]=GFdivide(Ecoe[i][j],diagonal);
        errors[i]=GFdivide(errors[i],diagonal);
    for(k=0;k<N;k++)
    {
        if(k!=i)
        {
            int coefficient = Ecoe[k][i];
            for( int m=0;m<N;m++ )
                    Ecoe[k][m] = GFadd( Ecoe[k][m], GFmulti(coefficient, Ecoe[i][m]) );
            errors[k] =GFadd( errors[k], GFmulti(coefficient, errors[i]) );
        }
    }
    }
    for(k=0;k<N;k++)
        errors2[k]=errors[N-k-1];
    return errors2;
}
CodeArray calecode(CodeArray msgcode,int n,int k)
{
    int i,j,msgnum[k],len;
    //printf("k=%d\n",k);
    for(i=0;i<=k-1;i++) msgnum[i]=codetonum(msgcode[i]);
    //printf("��������\n");
    //for(i=0;i<=k-1;i++) printf("%d ",msgnum[i]);
    //printf("\n");
    CodeArray Ecode=(CodeArray)malloc((n-k)*9);
    char temp[9];
    //�����Ƿ��̵ĸ����֣�
    int* Const=(int*)malloc((n-k)*sizeof(int));//n-k�����̣�ÿ��������һ������
    int (*Ecoe)[n-k]=(int(*)[n-k])malloc((n-k)*(n-k)*sizeof(int));
    //int Ecoee[n-k][n-k];//n-k�����̣�ÿ��������(n-k)��ϵ��
    int* Enum; //=(int*)malloc((n-k)*sizeof(int)); //E0��E1��...��E(n-k-1)δ֪��
    for(i=0;i<=n-k-1;i++) //i:��i������
    {
        //x=alphato(i+1);
        //GFmulti(msgnum[j],alphato(i*(n-j-1)))
        for(j=0,Const[i]=0;j<=k-1;j++) {Const[i]=GFadd(GFmultialphato(msgnum[j],i*(n-j-1)),Const[i]);} //����Const[i]
        //printf("Constant%d now:%d add1:%d msgnum:%d ...=%d\n",i,Const[i],msgnum[j],alphato((i+1)*(n-j-1)));
        for(j=0;j<=n-k-1;j++) Ecoe[i][j]=alphato(i*j); //����E[j]��ϵ�� ԭΪn-k-j-1
    }
    //printf("��ʼ��\n");
    //PrintEQA(n-k,Const,Ecoe,n-k);
    //system("pause");
    Enum=GaussEliminate(n-k,Const,Ecoe);
    //printf("�������֣�\n");
    //for(j=0;j<=n-k-1;j++) printf("%d ",Enum[j]);
    //printf("\n");
    for(i=0;i<=n-k-1;i++)
    {
        itoa(Enum[i],temp,2);
        len=strlen(temp);
        for(j=0;j<8-len;j++)
            Ecode[i][j]='0';
        strcpy(Ecode[i]+8-len,temp);
    }
    return Ecode;
}

CodeArray* todatacode(Qrcodeinfo* qrcode,CodeArray msgcode)
{
    int m=0,t=0,i,j,k,n,num=(qrcode->ecodata.blockn[0]+qrcode->ecodata.blockn[1])*2;//ÿ��blockn���������ֺ;������ָ���һ��CodeArray���ʳ�2
    //CodeArray datacode[num];
    CodeArray* datacode=(CodeArray*)malloc(num*sizeof(CodeArray));
    CodeArray p;
    for(j=0;j<=1;j++)
    {
        int Dn=qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
        n=qrcode->ecodata.blockn[j];  //�ڣ�j+1�����Ϳ�Ŀ���
        for(k=0;k<=n-1;k++)
        {
            p=(CodeArray)malloc(Dn*9);
            for(i=0;i<=Dn-1;i++)
                strcpy(p[i],*msgcode++);
            datacode[m++]=p;
        }
    }
    for(j=0;j<=1;j++)
    {
        int Dn=qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
        int En=qrcode->ecodata.CKR[j][0]-qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ�ľ���������
        n=qrcode->ecodata.blockn[j];
        for(k=0;k<=n-1;k++)
        {
            p=calecode(datacode[t++],Dn+En,Dn);
            //printf("��%d�����������Ѽ���,n=%d\n",k+1,n);
            datacode[m++]=p;
        }
    }
    return datacode;
}
void Printdata(CodeArray* datacode,int num,Qrcodeinfo* qrcode)
{
    int test,m=0,i,j,k,n;
    for(j=0;j<=1;j++)
    {
        int Dn=qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
        n=qrcode->ecodata.blockn[j];  //�ڣ�j+1�����Ϳ�Ŀ���
        /*for(k=0;k<=n-1;k++)
        {
            for(i=0;i<=Dn-1;i++)
                puts(datacode[m][i]);
            printf("Dn������������%d\n",Dn);
            m++;

        }*/
    }
    for(j=0;j<=1;j++)
    {
        //int Dn=qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ������������
        int En=qrcode->ecodata.CKR[j][0]-qrcode->ecodata.CKR[j][1]; //�ڣ�j+1�����Ϳ�ľ���������
        n=qrcode->ecodata.blockn[j];
        /*for(k=0;k<=n-1;k++)
        {
            for(test=0;test<=En-1;test++)
                puts(datacode[m][test]);
            printf("En������������%d\n",En);
            m++;
        }*/

    }
}
void drawpixel(double x,double y,double len,int col)
{


    if(col==0)
    al_draw_filled_rectangle(x, y, x + len, y + len, al_map_rgb(255, 255, 255)); //0���
    if(col==1)
    al_draw_filled_rectangle(x, y, x + len, y + len, al_map_rgb(0, 0, 0)); //1���
    if(col==2)
        al_draw_filled_rectangle(x, y, x + len, y + len, al_map_rgb(255, 0, 0)); //1���
    if(col==3)
        al_draw_filled_rectangle(x, y, x + len, y + len, al_map_rgb(0, 255, 0));;
    if(col==4)
        al_draw_filled_rectangle(x, y, x + len, y + len, al_map_rgb(96, 255, 255)); //ǳ��
}
void addrectframe(char(*finbin)[],Qrcodeinfo* qrcode,int x,int y,int len,char col)
{
    int i,j,l=qrcode->length;
    char (*fbin)[l]=finbin;
    for(i=x,j=y;j<=len+y-1;j++) fbin[i][j]=col;
    for(i=x,j=y;i<=len+x-1;i++) fbin[i][j]=col;
    for(i=x+len-1,j=y;j<=len+y-1;j++) fbin[i][j]=col;
    for(i=x,j=len+y-1;i<=len+x-1;i++) fbin[i][j]=col;
}
void addalignpatt(char(*finbin)[],Qrcodeinfo* qrcode)
{
    int i,j,l=qrcode->length,coordn=sqrt(qrcode->align_n+3);
    char(*fbin)[l]=finbin;
    //for(i=0;i<=coordn-1;i++)
        //printf("coord%d=%d\n",i,qrcode->align_coord[i]);
    for(i=0;i<=coordn-1;i++)
        for(j=0;j<=coordn-1;j++)
    {
        if(i==0&&j==0) continue;
        if(i==0&&j==coordn-1) continue;
        if(i==coordn-1&&j==0) continue;
        //printf("coord[%d]=%d coord[%d]=%d\n",i,qrcode->align_coord[i],j,qrcode->align_coord[j]);
        fbin[qrcode->align_coord[i]][qrcode->align_coord[j]]='1';
        addrectframe(finbin,qrcode,qrcode->align_coord[i]-1,qrcode->align_coord[j]-1,3,'0');
        addrectframe(finbin,qrcode,qrcode->align_coord[i]-2,qrcode->align_coord[j]-2,5,'1');
    }
}
void addpositdete(char(*finbin)[],Qrcodeinfo* qrcode)
{
    int i,j,len=qrcode->length;
    char (*fbin)[len]=finbin;
    addrectframe(finbin,qrcode,0,0,7,'1');
    addrectframe(finbin,qrcode,0,len-7,7,'1');
    addrectframe(finbin,qrcode,len-7,0,7,'1');
    addrectframe(finbin,qrcode,1,1,5,'0');
    addrectframe(finbin,qrcode,1,len-6,5,'0');
    addrectframe(finbin,qrcode,len-6,1,5,'0');
    for(i=2;i<=4;i++)
    {
        for(j=2;j<=4;j++) fbin[i][j]='1';
        for(j=len-5;j<=len-3;j++) fbin[i][j]='1';
    }
    for(i=len-5;i<=len-3;i++)
        for(j=2;j<=4;j++) fbin[i][j]='1';
}
void addseparator(char(*finbin)[],Qrcodeinfo*qrcode)
{
    int l=qrcode->length;
    char(*fbin)[l]=finbin;
    addrectframe(fbin,qrcode,0,0,8,'0');
    addrectframe(fbin,qrcode,0,l-8,8,'0');
    addrectframe(fbin,qrcode,l-8,0,8,'0');
}
void addtimingpatt(char(*finbin)[],Qrcodeinfo* qrcode)
{
    int i,j,count=1,len=qrcode->length;
    char(*fbin)[len]=finbin;
    for(i=6,j=8;j<=len-1;j++,count++) if(fbin[i][j]==0) fbin[i][j]=count%2+48;  //'0'��ASCII����48
    count=1;
    for(j=6,i=8;i<=len-1;i++,count++) if(fbin[i][j]==0) fbin[i][j]=count%2+48;
}
void addverinfo(char(*finbin)[],Qrcodeinfo* qrcode)
{
    if(qrcode->ver<7) return;
    int i,j,len=qrcode->length,n=0;
    char(*fbin)[len]=finbin;
    for(i=5;i>=0;i--)
        for(j=len-9;j>=len-11;j--)
            fbin[i][j]=verinfo[qrcode->ver-7][n++];
    n=0;
    for(j=5;j>=0;j--)
        for(i=len-9;i>=len-11;i--)
        fbin[i][j]=verinfo[qrcode->ver-7][n++];
}
void format_init(char(*finbin)[],Qrcodeinfo* qrcode)
{
    int i,j,len=qrcode->length;
    char(*fbin)[len]=finbin;
    for(i=0,j=8;i<=5;i++) fbin[i][j]='0';
    for(i=7,j=8;i<=8;i++) fbin[i][j]='0';
    for(i=len-8,j=8;i<=len-1;i++) fbin[i][j]='0';
    for(i=8,j=len-1;j>=len-8;j--) fbin[i][j]='0';
    for(i=8,j=8;j>=7;j--) fbin[i][j]='0';
    for(i=8,j=5;j>=0;j--) fbin[i][j]='0';
}
void addformatinf(char(*finbin)[],Qrcodeinfo* qrcode)
{
    int i,j,n=14,len=qrcode->length;
    char(*fbin)[len]=finbin;
    for(i=0,j=8;i<=5;i++) fbin[i][j]=formatinfo[n--];
    for(i=7,j=8;i<=8;i++) fbin[i][j]=formatinfo[n--];
    fbin[len-8][8]='1';
    for(i=len-7,j=8;i<=len-1;i++) fbin[i][j]=formatinfo[n--];
    n=14;
    for(i=8,j=len-1;j>=len-8;j--) fbin[i][j]=formatinfo[n--];
    fbin[8][7]=formatinfo[n--];
    for(i=8,j=5;j>=0;j--) fbin[i][j]=formatinfo[n--];

}
void addfuncpatt(char(*finbin)[],Qrcodeinfo* qrcode)
{
    addseparator(finbin,qrcode);
    addpositdete(finbin,qrcode);
    addalignpatt(finbin,qrcode);
    addtimingpatt(finbin,qrcode);
    addverinfo(finbin,qrcode);
    format_init(finbin,qrcode);
    addformatinf(finbin,qrcode);

    //��ʽ��Ϣ���汾��Ϣ���ڱ������򣬵�������ͳһ����Ĥ���ʿ�����Ϊ����ͼ��
}
void addphotopart(char(*photobin)[],Qrcodeinfo* qrcode)
{
    int i,j,min,max;
    char (*binmatrix)[qrcode->length]=photobin;
    min=qrcode->length/2-(HALFIMAGESIZE-1);
    max=qrcode->length/2+HALFIMAGESIZE+1;
    for(i=min;i<=max;i++)
        for(j=min;j<=max;j++)
            binmatrix[i][j]='0';
}
void maskinit(char(*mask)[],Qrcodeinfo* qrcode,int mode)
{
    int i,j,len=qrcode->length;
    char(*msk)[len]=mask;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
    {
        if(mode==0) {if((i+j)%2==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==1) {if(i%2==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==2) {if(j%3==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==3) {if((i+j)%3==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==4) {if((i/2+j/3)%2==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==5) {if(i%2==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==6) {if(i%2==0) msk[i][j]='1';else msk[i][j]='0';}
        if(mode==7) {if(i%2==0) msk[i][j]='1';else msk[i][j]='0';}
    }
}
void masksuperposition(char(*findbin)[],char(*mask)[],Qrcodeinfo* qrcode)
{
    int i,j,add,len=qrcode->length;
    char(*fdbin)[len]=findbin;
    char(*msk)[len]=mask;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
        if(fdbin[i][j]!=0)
        {
            add=(fdbin[i][j]-48)^(msk[i][j]-48);
            fdbin[i][j]=48+add;
        }
}
void toQRbmp(int len,char(*bin)[len])
{
    double len0=(int)((double)TOTALLENGTH/(double)len);
    int i,j;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
           if(bin[i][j]=='1') drawpixel(50+len0*j,50+len0*i,len0,1);
}
void toQRbmp2(int len,char(*bin)[len])//��findbinʹ��
{
    double len0=(double)TOTALLENGTH/len;
    int i,j;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
           {if(bin[i][j]=='1') drawpixel(50+len0*j,50+len0*i,len0,2);
           if(bin[i][j]=='0') drawpixel(50+len0*j,50+len0*i,len0,3);}
}
void toQRbmp3(int len,char(*bin)[len])
{
    double len0=(double)TOTALLENGTH/len;
    int i,j;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
           {if(bin[i][j]=='1') drawpixel(50+len0*j,50+len0*i,len0,2);
           if(bin[i][j]=='0') drawpixel(50+len0*j,50+len0*i,len0,4);}//ǳ��ר���ڱ�ʶfinbin��ǳɫ}
}
void finbin_init(Qrcodeinfo* qrcode,char(*finbin)[])
{
    int i,j,len=qrcode->length;
    char(*fbin)[len]=finbin;
    for(i=0;i<=len-1;i++)
        for(j=0;j<=len-1;j++)
            fbin[i][j]=0;
}
int islinefull(Qrcodeinfo* qrcode,char(*finbin)[],int line)
{
    int len=qrcode->length,i;
    char(*fbin)[len]=finbin;
    for(i=0;i<=len-1;i++)
        if(fbin[i][line]==0) return 0;
    return 1;
}
void nextblock(Qrcodeinfo* qrcode,char(*finbin)[],char(*findbin)[],char block)
{
    int len=qrcode->length,count;
    char(*fbin)[len]=finbin;
    char(*fdbin)[len]=findbin;
    static int x=0,y=0,flag1=0,flag2=0,init=1;
    //������ģ��λ����ֱ�����Ҳ�ʱflag1=0 ���������ʱflag2=0
    //���
    if(init==1) {x=len-1;y=len-1;init=0;}
    for(count=0;count<=10000;count++)
    {
        if(x==len-9&&y==0) break;
        if(fbin[x][y]==0&&fdbin[x][y]==0) break;
        if(x==len-1) if(flag2==1)
        {
            if(flag1==1)
            {
                flag2=0;
                if(islinefull(qrcode,finbin,y-1)) y=y-2;
                else y--;
                flag1=0;
                if(fbin[x][y]==0) break;
                else continue;
            }
        }
        if(x==0) if(flag2==0)
        {
            if(flag1==1)
            {
                flag2=1;
                if(islinefull(qrcode,finbin,y-1)) y=y-2;
                else y--;
                flag1=0;
                if(fbin[x][y]==0) break;
                else continue;
            }
        }
        if(flag1==0&&flag2==0) {y--;flag1=1;}
        else if(flag1!=0&&flag2==0) {x--;y++;flag1=0;}
        else if(flag1==0&&flag2!=0) {y--;flag1=1;}
        else if(flag1!=0&&flag2!=0) {x++;y++;flag1=0;}
        if(fbin[x][y]==0) {break;}
        //system("pause");
    }
    if(fbin[x][y]==0)
    fdbin[x][y]=block;//printf("lastfill:x=%d,y=%d block=%d\n",x,y,block);
}
void filldata(Qrcodeinfo* qrcode,CodeArray* datacode,char(*finbin)[],char(*findbin)[])
{
    //arrayn=(qrcode->ecodata.blockn[0]+qrcode->ecodata.blockn[1])*2;
    int i,j,k,Dn1=qrcode->ecodata.CKR[0][1],Dn2=qrcode->ecodata.CKR[1][1];
    int En1=qrcode->ecodata.CKR[0][0]-Dn1;
    int blockn=qrcode->ecodata.blockn[0]+qrcode->ecodata.blockn[1];
    int blockn1=qrcode->ecodata.blockn[0],count=0;
    //�Խ϶̳��ȵ���������CodeArray������
    for(i=0;i<=Dn1-1;i++)
        for(j=0;j<=blockn-1;j++)
            for(k=0;k<=7;k++)
            {nextblock(qrcode,finbin,findbin,datacode[j][i][k]);if(datacode[j][i][k]==18) printf("error18: j=%d i=%d k=%d\n",j,i,k);}
    //�Խϳ����ȵ���������CodeArray������
    for(i=Dn1;i<=Dn2-1;i++)
        for(j=blockn1;j<=blockn-1;j++)
            for(k=0;k<=7;k++)
            {nextblock(qrcode,finbin,findbin,datacode[j][i][k]);if(datacode[j][i][k]==18) printf("error18: j=%d i=%d k=%d\n",j,i,k);}
    //�Ծ������ֵ����루���п�ľ�������CodeArray����һ������
    for(i=0;i<=En1-1;i++)
        for(j=blockn;j<=2*blockn-1;j++)
        for(k=0;k<=7;k++)
        {nextblock(qrcode,finbin,findbin,datacode[j][i][k]);if(datacode[j][i][k]==18) printf("error18: j=%d i=%d k=%d\n",j,i,k);}
    for(i=0;i<=20;i++) {if(count==0){count=1;}nextblock(qrcode,finbin,findbin,'0');}
}
void welcome()
{
    printf("QR CODE ENCODER\n");
    printf("VER:2.0\n");
}
int isfromfile(char* text)
{
    char *p;
    if((p=strstr(text,file_identifier))!=NULL)
        {if(*(p+4)==0) return 1;else return 0;}
    else return 0;
}
void str_check(char* text,int* pmode,int* pver,int argc,char** argv)
{
    int mode,ver,num,flag=1,len;
    //flag����Ƿ���Ҫ�ڶ�������
    FILE* fp;
    for(;;)
    {
    if(argc>1&&flag==1)
    {
        for(num=2;num<=argc;num++)
        {
            strcat(text,argv[num-1]);
            strcat(text," ");
        }
    }
    else
    {
        printf("������һ�����ֻ�ASCII�룺\n");
        gets(text);
    }

        if(isfromfile(text))
        {
            printf("���ļ�%s��ȡ...\n",text);
            if((fp=fopen(text,"r"))==NULL)
                {printf("δ�ҵ�%s\n",text);continue;}
            else
            {
                fseek(fp,0L,SEEK_END);
                len=ftell(fp);
                printf("len=%d\n",len);
                rewind(fp);
                fread(text,1,len,fp);
                text[len]=0;
                fclose(fp);
                printf("����textΪ%s\n",text);
            }
        }
        if(*text==0) {printf("�����û����������Ŷ�����������룺\n");continue;}
        mode=str_analysis(text);
        ver=ver_determine(text,mode);    //ȷ���汾
        if(ver>0&&ver<=MAXVERSION) {printf("��ȷ���汾Ϊ%d\n",ver);break;}
        else if(ver==-1) printf("�������ݹ��������������룺\n");
        else if(ver==-2) printf("δ֪�����볢���������룺\n");
    }
    *pmode=mode;
    *pver=ver;
}
int main(int argc, char** argv)
{
    static Qrcodeinfo qrdata;
    Qrcodeinfo* qrcode=&qrdata;
    char text[MAXNUM],(*part)[4],bin[MAXNUM]={0};
    CodeArray msgcode,*datacode;
    int mode,ver;
    int *pmode=&mode,*pver=&ver;
    welcome();
    str_check(text,pmode,pver,argc,argv);
    if(mode==NUMBERMODE) printf("��ȷ��ģʽΪ����ģʽ\n");
    if(mode==ASCIIMODE) printf("��ȷ��ģʽΪ8λ�ֽ�ģʽ\n");
    QRinit(qrcode,ver);
    //system("pause");
    char (*finbin)[qrcode->length]=(char(*)[qrcode->length])malloc(qrcode->length*qrcode->length);
    char (*findbin)[qrcode->length]=(char(*)[qrcode->length])malloc(qrcode->length*qrcode->length);
    char (*mask)[qrcode->length]=(char(*)[qrcode->length])malloc(qrcode->length*qrcode->length);
    char (*photobin)[qrcode->length]=(char(*)[qrcode->length])malloc(qrcode->length*qrcode->length);

    //findbin:ר�Ŵ����������
    finbin_init(qrcode,finbin);
    finbin_init(qrcode,findbin);
    finbin_init(qrcode,photobin);
    addphotopart(photobin,qrcode);
    bin_init(ver,mode,bin,strlen(text));
    if(mode==NUMBERMODE)
    {
    part=num_strdivide(text);
    numtobin(part,bin);
    }
    if(mode==ASCIIMODE)
        asciitobin(text,bin);
    terminator(qrcode,bin);
    msgcode=tomsgcode(qrcode,bin);
    datacode=todatacode(qrcode,msgcode);
    //Printdata(datacode,num,qrcode);
    //------------------------------------
        printf("���ڼ���ͼ�ν���...\n");
    if (!al_init()) {
      printf("Could not init Allegro.\n");
      return -1;
   }

    ALLEGRO_DISPLAY *display = al_create_display(BMPLENGTH, BMPLENGTH);
    if (!display) {
      printf("Error creating display\n");
      return -1;
    }
    ALLEGRO_BITMAP *screen=al_create_bitmap(BMPLENGTH,BMPLENGTH);
    ALLEGRO_KEYBOARD_STATE kbdstate;
    //al_set_target_bitmap(screen);
    al_install_keyboard();
    al_init_primitives_addon();
    //init_platform_specific();
    al_clear_to_color(al_map_rgb(255, 255, 255));
    addfuncpatt(finbin,qrcode);
    filldata(qrcode,datacode,finbin,findbin);
    maskinit(mask,qrcode,3);
    masksuperposition(findbin,mask,qrcode);
    toQRbmp(qrcode->length,finbin);
    toQRbmp(qrcode->length,findbin);
    al_flip_display();
    do al_get_keyboard_state(&kbdstate);
    while(!al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE));
    return 0;
}
