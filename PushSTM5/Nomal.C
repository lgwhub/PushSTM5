//nomal.c
#include "Nomal.h"



//////////
 /* �������ڼ��ַ���������ֱ��0X00 */
uchar PutString(uchar *ps,uchar *pd,uchar max_ps) 
{uchar len=0; /* ������� */
 uchar temp;
while(len<max_ps)
    {temp=*(ps+len);  /* ԭ */
     *(pd+len)=temp;  /* Ŀ�� */
     if(temp==0x00)break;
     else{len++;
         };
    };
return len;   /* ָ��pd��0X00λ  */
}
///

uchar CompareCharChar(uchar *chr1,uchar *chr2,uchar len)
{
 uchar i;
 for(i=0;i<len;i++)
    {
    if(*(chr1+i)!=*(chr2+i))
          {return 0;
          };
    };
return 1;
}

///////////

uchar MakeValAsc8(uchar *StrHead,uchar Val,uchar *StrEnd,uchar *out)	//8λ����ת��Ϊʮ���Ƶ�ASC�룬��ǰ��׺
{
 /* �������ڼ��ַ���������ֱ��0X00 */
//uchar PutString(uchar *ps,uchar *pd,uchar max_ps) 
uchar i;

i=PutString(StrHead,out,20);
out[i]=HexToAsc(Val/100%10);i++;
out[i]=HexToAsc(Val/10%10);i++;
out[i]=HexToAsc(Val%10);i++;
i+=PutString(StrEnd,&out[i],20);
return i;
}
/*
uchar MakeValAsc16(uchar *StrHead,uint16 Val,uchar *StrEnd,uchar *out,uchar point)	//16λ����ת��Ϊʮ���Ƶ�ASC�룬��ǰ��׺
{
 // �������ڼ��ַ���������ֱ��0X00
//uchar PutString(uchar *ps,uchar *pd,uchar max_ps) 
uchar i;
uchar temp;
uchar flag;

flag=0;

	i=PutString(StrHead,out,20);
	temp=Val/10000%10;
	if((temp>0)||flag)
			{
				flag=1;
				out[i]=HexToAsc(temp);i++;
			}
	temp=Val/1000%10;
	if((temp>0)||flag)
			{
				flag=1;
				out[i]=HexToAsc(temp);i++;
			}
	temp=Val/100%10;
	if((temp>0)||flag)
			{
				flag=1;
				out[i]=HexToAsc(temp);i++;
			}
	temp=Val/10%10;
	
	if((temp>0)||flag||point)
			{
				out[i]=HexToAsc(temp);i++;
			}
	
	if(point)	//С����
			{//���Ų���ʡ20081117
		out[i]='.';i++;		
		}
	out[i]=HexToAsc(Val%10);i++;
	
	i+=PutString(StrEnd,&out[i],20);
	return i;
}
*/
//////////////
/*
uchar MakeValAsc32(uchar *StrHead,uint32 Val,uchar *StrEnd,uchar *out,uchar point)	//32λ����ת��Ϊʮ���Ƶ�ASC�룬��ǰ��׺
{
uchar i;
uchar temp;
uchar flag;
	flag=0;
	i=PutString(StrHead,out,20);
	
	temp=Val/1000000000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/100000000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/10000000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/1000000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/100000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/10000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/1000%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/100%10;
			if((temp>0)||flag)
					{
						flag=1;
						out[i]=HexToAsc(temp);i++;
					}
	temp=Val/10%10;
	if((temp>0)||flag||point)
			{
				out[i]=HexToAsc(temp);i++;
			}
	if(point)	//С����
		{
			out[i]='.';i++;	
		}
	temp=Val%10;
	out[i]=HexToAsc(temp);i++;
	i+=PutString(StrEnd,&out[i],20);
	return i;

}
*/
/*
uchar MakeValHex16(uchar *StrHead,uint Val,uchar *StrEnd,uchar *out)	//16λ����ת��ΪHEX��ASC�룬��ǰ��׺
{
 //�������ڼ��ַ���������ֱ��0X00
//uchar PutString(uchar *ps,uchar *pd,uchar max_ps) 
uchar i;

i=PutString(StrHead,out,20);
out[i]=HexToAsc(Val/0x1000%0x10);i++;
out[i]=HexToAsc(Val/0x100%0x10);i++;
out[i]=HexToAsc(Val/0x10%0x10);	i++;
out[i]=HexToAsc(Val%0x10);i++;
i+=PutString(StrEnd,&out[i],20);
return i;
}
*/
/********************************************************************************/
/*
uchar IsNumberAsc(uchar x)   //�ж��Ƿ�Ϊ����0~9
{if(x>'9')
     {return 0;
     }
 else if(x<'0')
     {return 0;
     }
 else{return 1;
     };
}
*/
/************************************************************************/
/*                                                                      */
/*                     ASC_2��  ת��ͨ���ӳ���                           */
/*                                                                      */
/*          HexToAsc  ���ֽڶ�����ת��Ϊ1λASC_2��   �ӳ���              */
/************************************************************************/
uchar HexToAsc(uchar x)   /*  1/2hex>>1asc2   */
{ x&=0x0f;
 if(x>9){x-=0x0a;x+='A';}else{x+='0';};
 return x;
}

/************************************************************************/
/*          AscToHex  1λASC_2��ת��Ϊ���ֽڶ�����   �ӳ���              */
/*                        1ASC>>1/2HEX                                  */
/************************************************************************/

uchar AscToHex(uchar x)     
{
x&=0xFF;	
if(x>='a')
    {x-=87;//{x-='a';x+=0x0a;}
    }
else if(x>'9')
    {x-=55;//{x-='A';x+=0x0a;
    }
else{x-='0';
    };
x&=0x0f;
return x;
}

//////////////////////////////////////////////////////////////////////////
/*
uint16 NumberAscStringToInt16(uchar *p)	//���5λASC��������ַ���ת��Ϊ16λ�޷�������
{
uint32 word2;
uchar i;
word2=0;
for(i=0;i<5;i++)
	{
	if(IsNumberAsc(*p))
        	{
        	word2=word2*10+AscToHex(*p);
        	}
        else break;
        p++;
        };
if(word2>65535)word2=65535;
   return  (uint16)word2;    	
}
*/
/////////////////////////////////////////////