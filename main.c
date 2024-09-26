#include <stdio.h>
#include <stdlib.h>

struct BITMAPFILEHEADER {
    unsigned short int bfType;       //位图文件的类型，必须为BM
    unsigned long bfSize;       //文件大小，以字节为单位
    unsigned short int bfReserverd1; //位图文件保留字，必须为0
    unsigned short int bfReserverd2; //位图文件保留字，必须为0
    unsigned long bfOffBits;  //位图文件头到数据的偏移量，以字节为单位
};

struct BITMAPINFOHEADER {
    long biSize;                        //该结构大小，字节为单位
    long biWidth;                     //图形宽度以象素为单位
    long biHeight;                     //图形高度以象素为单位
    short int biPlanes;               //目标设备的级别，必须为1
    short int biBitcount;             //颜色深度，每个象素所需要的位数
    short int biCompression;        //位图的压缩类型
    long biSizeImage;              //位图的大小，以字节为单位
    long biXPelsPermeter;       //位图水平分辨率，每米像素数
    long biYPelsPermeter;       //位图垂直分辨率，每米像素数
    long biClrUsed;            //位图实际使用的颜色表中的颜色数
    long biClrImportant;       //位图显示过程中重要的颜色数
};

struct bmp {
    struct BITMAPFILEHEADER file; //文件信息区
    struct BITMAPINFOHEADER info; //图象信息区
};

struct bmp readBmpImage(void); //函数声明
struct bmp color2grey(void); //函数声明

int main(void) {
    struct bmp testImage;          //定义一个结构变量
    testImage = readBmpImage(); //读取一个位图
    FILE *newFp;
    newFp = fopen("d:\\CLion Project\\BMPtest\\greyOutput.bmp", "wb");
    if (newFp == NULL) {
        printf("Failed to create the new file!");
    }
    fwrite(&testImage.file, sizeof(testImage.file), 1, newFp);
    fwrite(&testImage.info, sizeof(testImage.info), 1, newFp);
    return 0;
}

struct bmp color2grey(void){

}

struct bmp readBmpImage(void) {
    struct bmp image;        //定义一个位图结构
    FILE *fp;
    if ((fp = fopen("d:\\CLion Project\\BMPtest\\BlackMythScreenshotBmpTest.bmp", "r")) == NULL) {
        printf("can't open the bmp imgae.\n ");
        exit(0);
    } else {
        fread(&image.file.bfType, sizeof(char), 1, fp);
        printf("类型为%c", image.file.bfType);
        fread(&image.file.bfType, sizeof(char), 1, fp);
        printf("%c\n", image.file.bfType);
        fread(&image.file.bfSize, sizeof(long), 1, fp);
        printf("文件长度为%d\n", image.file.bfSize);
        fread(&image.file.bfReserverd1, sizeof(short int), 1, fp);
        printf("保留字1为%d\n", image.file.bfReserverd1);
        fread(&image.file.bfReserverd2, sizeof(short int), 1, fp);
        printf("保留字2为%d\n", image.file.bfReserverd2);
        fread(&image.file.bfOffBits, sizeof(long), 1, fp);
        printf("偏移量为%d\n", image.file.bfOffBits);
        fread(&image.info.biSize, sizeof(long), 1, fp);
        printf("此结构大小为%d\n", image.info.biSize);
        fread(&image.info.biWidth, sizeof(long), 1, fp);
        printf("位图的宽度为%d\n", image.info.biWidth);
        fread(&image.info.biHeight, sizeof(long), 1, fp);
        printf("位图的高度为%d\n", image.info.biHeight);
        fread(&image.info.biPlanes, sizeof(short), 1, fp);
        printf("目标设备位图数%d\n", image.info.biPlanes);
        fread(&image.info.biBitcount, sizeof(short), 1, fp);
        printf("颜色深度为%d\n", image.info.biBitcount);
        fread(&image.info.biCompression, sizeof(long), 1, fp);
        printf("位图压缩类型%d\n", image.info.biCompression);
        fread(&image.info.biSizeImage, sizeof(long), 1, fp);
        printf("位图大小%d\n", image.info.biSizeImage);
        fread(&image.info.biXPelsPermeter, sizeof(long), 1, fp);
        printf("位图水平分辨率为%d\n", image.info.biXPelsPermeter);
        fread(&image.info.biYPelsPermeter, sizeof(long), 1, fp);
        printf("位图垂直分辨率为%d\n", image.info.biYPelsPermeter);
        fread(&image.info.biClrUsed, sizeof(long), 1, fp);
        printf("位图实际使用颜色数%d\n", image.info.biClrUsed);
        fread(&image.info.biClrImportant, sizeof(long), 1, fp);
        printf("位图显示中比较重要颜色数%d\n", image.info.biClrImportant);
    }
    return image;
}
