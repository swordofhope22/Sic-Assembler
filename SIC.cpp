#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
void printstr(FILE *code,char name[]){
	
	if(name[0]=='C'){
	
	for(int i=2;i<strlen(name)-1;i++)
	
	fprintf(code,"%x",name[i]);
}
else if (name[0]=='X'){
	for(int i=2;i<strlen(name)-1;i++)
	
	fprintf(code,"%c",name[i]);
}


	

 

	
}
int main(){
	
FILE *code,*optab,*symb,*med,*obj ,*hte;
char opcode[10],operand[20],label[10],mnemonic[10],hex[10] ,operand1[10],object[10],location[10],mnm[10],labelsy[10],opcodet[10],fhte[100],format[10],ex[10],lcsy[10],git[20],htte[100]={"\0"}; //variables declaration
int lc,start,length,end,index=1,c=1,k=0,disp,mn,sy,r=0,lcstart,lcend,current,htlength=0;
char a[100][10];
int m[100];
code=fopen("code.txt","r");
optab=fopen("optab.txt","r");
symb=fopen("symbol.txt","w+");
med=fopen("med.txt","w+");
obj=fopen("obj.txt","w+");
hte=fopen("hte.txt","w+");
fscanf(code,"%s\t%s\t%s",label,opcode,operand);	

lc=atoi(operand); 
start=lc;

fprintf(symb,"label\tlocation\n" );
fprintf(med,"label\topcode\toperand\tlocation\n" );
fprintf(obj,"label\topcode\toperand\t location\tobjectcode\n" );
fprintf(obj,"%s\t%s\t%s\t  %04x\t\t   -\n",label,opcode,operand,lc);
fscanf(code,"%s\t%s\t%s",label,opcode,operand);
printf("%x",lc);
	while(strcmp(opcode,"END")!=0){
		fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
			if(strcmp(label,"-")!=0){
				
			
				fprintf(symb,"%s\t%04x\n",label,lc);
				
			}
				
			 if(strcmp(opcode,"WORD")==0)
				lc=lc+3;
			else if (strcmp(opcode,"BYTE")==0){
				if(operand[0]=='C'){
				
				lc=lc+strlen(operand)-3;
			}
				if(operand[0]=='X'){
				
				lc=lc+1;
			
			}
		}
			else if (strcmp(opcode,"RESW")==0)
			lc=lc+(atoi(operand)*3);
			else if (strcmp(opcode,"RESB")==0)
			lc=lc+(atoi(operand));
			else 
			lc=lc+3;
			
			
			
			fscanf(code,"%s\t%s\t%s",label,opcode,operand);
				
		}	
	end=lc;
	fprintf(med,"%s\t%s\t%s\t%04x\n",label,opcode,operand,lc);
	rewind(med);
	rewind(symb);
	fscanf(med,"%s%s%s%s",label,opcode,operand,location);
	fscanf(med,"%s%s%s%s",label,opcode,operand,location);
	puts(opcode);
	while(strcmp(opcode,"END")!=0){

				if(strcmp(opcode,"WORD")==0){
				
					fprintf(obj,"%s\t%s\t%s\t  %04s\t\t",label,opcode,operand,location);					
					fprintf(obj,"    %06x\n",atoi(operand));

				}
				
				else if(strcmp(opcode,"RESW")==0||strcmp(opcode,"RESB")==0){
					strcpy(object,"-");
					fprintf(obj,"%s\t%s\t%s\t  %04s\t\t        %s\n",label,opcode,operand,location,object);
	}
				else if(strcmp(opcode,"BYTE")==0){
					fprintf(obj,"%s\t%s\t%s\t  %04s\t\t    ",label,opcode,operand,location);
					printstr(obj,operand);
					fprintf(obj,"\n");
	
				}
				else if (operand[strlen(operand)-2]==',')  {
					rewind(optab);
					fscanf(optab,"%s%x",opcodet,&mn);
					while (strcmp(opcode,opcodet)!=0)
					fscanf(optab,"%s%x",opcodet,&mn);	
				rewind(optab);
				fscanf(symb,"%s%s",labelsy,lcsy);
				fscanf(symb,"%s%x",labelsy,&sy);
				strcat(labelsy,",X");
					while (strcmp(operand,labelsy)!=0){
					
					fscanf(symb,"%s%x",labelsy,&sy);
					strcat(labelsy,",X");
			
			}
					rewind(symb);
					sy=sy+pow(2,15);
					fprintf(obj,"%s\t%s\t%s\t  %04s\t\t    %02x%04x\n",label,opcode,operand,location,mn,sy);
				}
				else{
						rewind(optab);
					fscanf(optab,"%s%x",opcodet,&mn);
					while (strcmp(opcode,opcodet)!=0)
					fscanf(optab,"%s%x",opcodet,&mn);	
				rewind(optab);
				fscanf(symb,"%s%s",labelsy,lcsy);
				fscanf(symb,"%s%x",labelsy,&sy);
		
					while (strcmp(operand,labelsy)!=0){
					
					fscanf(symb,"%s%x",labelsy,&sy);
				
				
			
			}
					rewind(symb);
					
						
					fprintf(obj,"%s\t%s\t%s\t  %04s\t\t    %02x%04x\n",label,opcode,operand,location,mn,sy);
					
				}
		
	fscanf(med,"%s%s%s%s",label,opcode,operand,location);
	
}
fprintf(obj,"%s\t%s\t%s\t  %s\t\t     -",label,opcode,operand,location);
rewind(obj);
		fscanf(obj,"%s%s%s%s%s",label,opcode,operand,location,object);
		fscanf(obj,"%s%s%s%x%s",label,opcode,operand,&current,object);
		fprintf(hte,"H.%s.%06x.%06x\n",opcode,start,end-start);
		fscanf(obj,"%s%s%s%x%s",label,opcode,operand,&current,object);
		fprintf(hte,"T.%06x.",current);
		lcstart=start;
		lcend=start;
				while(strcmp(opcode,"END")!=0){
			start=0;
		if(index>10){
			index=1;
			
			
			fprintf(hte,"%02x%s\nT.%06x.",htlength,htte,current);
			strcpy(htte,"\0");
			lcstart=current;
			
		}
		if(strcmp(object,"-")==0){
			index=1;
			
			
			fprintf(hte,"%02x.%s\n",htlength,htte);
			c=0;
			strcpy(htte,"\0");
			
		}
		if(strcmp(object,"-")!=0&&c==0){
		fprintf(hte,"T.%06x.",current);
		c=1;
	}
		if(strcmp(object,"-")!=0){
		if(strcmp(opcode,"WORD")==0)
				htlength=htlength+3;
			else if (strcmp(opcode,"BYTE")==0){
				if(operand[0]=='C'){
				
				htlength=htlength+strlen(operand)-3;
			}
				if(operand[0]=='X'){
				
				htlength=htlength+1;
			
			}
		}
			else if (strcmp(opcode,"RESW")==0)
			htlength=htlength+(atoi(operand)*3);
			else if (strcmp(opcode,"RESB")==0)
			htlength=htlength+(atoi(operand));
			else 
			htlength=htlength+3;
		strcat(htte,object);
		strcat(htte,".");
	}
			
			index++;
		fscanf(obj,"%s%s%s%x%s",label,opcode,operand,&current,object);
	
		}
		fprintf(hte,"%02x.%s\n",htlength,htte);
		fprintf(hte,"\nE.%06x",start);
		
		puts(htte);
}
