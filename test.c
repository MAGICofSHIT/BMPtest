#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack(1)   //全紧凑模式

typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
}bitmapFileHeader;

typedef struct {
    unsigned int biSize;
    unsigned int biWidth;
    unsigned int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    unsigned int biXPixPerMeter;
    unsigned int biYPixPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
}bitmapInfoHeader;


typedef struct{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;

}rgbQUAD;

typedef struct{
    bitmapFileHeader bfHeader;
    bitmapInfoHeader biHeader;
    rgbQUAD palette[256];
    unsigned char *imgData;
}bmp;

int color2grey(FILE *fp){
    if((fp=fopen("..\\..\\BMPtest\\BlackMythScreenshotBmpTest.bmp","rb"))==NULL){
        perror("can not open file!");
        return -1;
    }
    //读入彩色bmp图像文件头，信息头和图像数据
    bitmapFileHeader bfHeader;
    fread(&bfHeader,14,1,fp);
    bitmapInfoHeader biHeader;
    fread(&biHeader,40,1,fp);
    int imSize=biHeader.biSizeImage;
    int width=biHeader.biWidth;
    int height=biHeader.biHeight;
    int bitCount=biHeader.biBitCount;
    int lineBytes=(width*bitCount+31)/32*4;

    fseek(fp,bfHeader.bfOffBits,SEEK_SET);
    unsigned char*imageData=(unsigned char*)malloc(imSize*sizeof(unsigned char));
    fread(imageData,imSize*sizeof(unsigned char),1,fp);
    fclose(fp);

    bmp b;
    int i,j,k;
    memcpy(&(b.bfHeader),&bfHeader,sizeof(bfHeader));
    memcpy(&(b.biHeader),&biHeader,sizeof(biHeader));
    b.bfHeader.bfOffBits=1078;  //因新增了调色板，需调整图像数据偏移位置
    b.biHeader.biBitCount=8;  //改变图像位数
    int lineBytes_new=(width*8+31)/32*4; //重新计算每行数据字节
    b.biHeader.biSizeImage=lineBytes_new*height; //改变图像数据大小
    b.bfHeader.bfSize=1078+b.biHeader.biSizeImage; //改变文件数据大小
    b.imgData=(unsigned char*)malloc(sizeof(unsigned char)*b.biHeader.biSizeImage);
    memset(b.imgData,0,sizeof(unsigned char)*b.biHeader.biSizeImage);
    for(i=0;i<256;i++){
        b.palette[i].rgbBlue=i;
        b.palette[i].rgbGreen=i;
        b.palette[i].rgbRed=i;
    }

    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            //将每一个像素都按公式y=B*0.299+G*0.587+R*0.114进行转化
            b.imgData[lineBytes_new*i+j]=imageData[lineBytes*i+j*3]*0.299+imageData[lineBytes*i+j*3+1]*0.587+imageData[lineBytes*i+j*3+2]*0.114;
        }
    }

    char savePath[]="..\\..\\BMPtest\\save_test.bmp";
    FILE *f=fopen(savePath,"wb");
    if(f==NULL){
        perror("can not open file!");
        return -2;
    }
    fwrite(&b.bfHeader,sizeof(bitmapFileHeader),1,f);
    fwrite(&b.biHeader,sizeof(bitmapInfoHeader),1,f);
    fwrite(&b.palette,1024,1,f);
    fwrite(b.imgData,sizeof(unsigned char)*b.biHeader.biSizeImage,1,f);
    fclose(f);

    free(imageData);
    free(b.imgData);
}
int main(){
    FILE *fp;
    int error = color2grey(fp);
    printf("yes");

    return 0;
}


