#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    long biSizeImage;              //图像数据的大小，以字节为单位
    long biXPelsPermeter;       //位图水平分辨率，每米像素数
    long biYPelsPermeter;       //位图垂直分辨率，每米像素数
    long biClrUsed;            //位图实际使用的颜色表中的颜色数
    long biClrImportant;       //位图显示过程中重要的颜色数
};

// 定义RGB调色板结构
struct RGBQUAD {
    unsigned char rgbBlue;         // 蓝色分量
    unsigned char rgbGreen;        // 绿色分量
    unsigned char rgbRed;          // 红色分量
    unsigned char rgbReserved;     // 保留字，通常为0
};

struct BMP {
    struct BITMAPFILEHEADER fileHeader; //文件信息区
    struct BITMAPINFOHEADER infoHeader; //图象信息区
    struct RGBQUAD palette[256];        //调色板，最多256色
    unsigned char *imgData;             //指向图像数据的指针
};

struct BMP readBmpImage(struct BMP originalImage,FILE **fp);

void color2grey(struct BMP colorImage, FILE *fp);

int main() {
    struct BMP originalImage;          //定义一个结构变量
    FILE *Fp;
    struct BMP colorImage = readBmpImage(originalImage,&Fp); //读取一个位图
    color2grey(colorImage, Fp);
    return 0;
}

struct BMP readBmpImage(struct BMP originalImage,FILE **fp) {
//    struct BMP image;
    if ((*fp = fopen("..\\..\\BMPtest\\BlackMythScreenshotBmpTest.bmp", "rb")) == NULL) {
        printf("can't open the BMP imgae.\n ");
        exit(0);
    } else {
        fread(&originalImage.fileHeader.bfType, sizeof(char), 1, *fp);
        printf("类型为%c", originalImage.fileHeader.bfType);
        fread(&originalImage.fileHeader.bfType, sizeof(char), 1, *fp);
        printf("%c\n", originalImage.fileHeader.bfType);
        fread(&originalImage.fileHeader.bfSize, sizeof(long), 1, *fp);
        printf("文件长度为%d\n", originalImage.fileHeader.bfSize);
        fread(&originalImage.fileHeader.bfReserverd1, sizeof(short int), 1, *fp);
        printf("保留字1为%d\n", originalImage.fileHeader.bfReserverd1);
        fread(&originalImage.fileHeader.bfReserverd2, sizeof(short int), 1, *fp);
        printf("保留字2为%d\n", originalImage.fileHeader.bfReserverd2);
        fread(&originalImage.fileHeader.bfOffBits, sizeof(long), 1, *fp);
        printf("偏移量为%d\n", originalImage.fileHeader.bfOffBits);
        fread(&originalImage.infoHeader.biSize, sizeof(long), 1, *fp);
        printf("此结构大小为%d\n", originalImage.infoHeader.biSize);
        fread(&originalImage.infoHeader.biWidth, sizeof(long), 1, *fp);
        printf("位图的宽度为%d\n", originalImage.infoHeader.biWidth);
        fread(&originalImage.infoHeader.biHeight, sizeof(long), 1, *fp);
        printf("位图的高度为%d\n", originalImage.infoHeader.biHeight);
        fread(&originalImage.infoHeader.biPlanes, sizeof(short), 1, *fp);
        printf("目标设备位图数%d\n", originalImage.infoHeader.biPlanes);
        fread(&originalImage.infoHeader.biBitcount, sizeof(short), 1, *fp);
        printf("颜色深度为%d\n", originalImage.infoHeader.biBitcount);
        fread(&originalImage.infoHeader.biCompression, sizeof(long), 1, *fp);
        printf("位图压缩类型%d\n", originalImage.infoHeader.biCompression);
        fread(&originalImage.infoHeader.biSizeImage, sizeof(long), 1, *fp);
        printf("位图大小%d\n", originalImage.infoHeader.biSizeImage);
        fread(&originalImage.infoHeader.biXPelsPermeter, sizeof(long), 1, *fp);
        printf("位图水平分辨率为%d\n", originalImage.infoHeader.biXPelsPermeter);
        fread(&originalImage.infoHeader.biYPelsPermeter, sizeof(long), 1, *fp);
        printf("位图垂直分辨率为%d\n", originalImage.infoHeader.biYPelsPermeter);
        fread(&originalImage.infoHeader.biClrUsed, sizeof(long), 1, *fp);
        printf("位图实际使用颜色数%d\n", originalImage.infoHeader.biClrUsed);
        fread(&originalImage.infoHeader.biClrImportant, sizeof(long), 1, *fp);
        printf("位图显示中比较重要颜色数%d\n", originalImage.infoHeader.biClrImportant);
    }
    return originalImage;
}

void color2grey(struct BMP colorImage, FILE *fp) {
    long width = colorImage.infoHeader.biWidth;
    long height = colorImage.infoHeader.biHeight;
    long lineBytes = (width * colorImage.infoHeader.biBitcount + 31) / 32 * 4;

    // 创建灰度图结构并更新头文件以适应灰度图
    struct BMP greyImage;
    greyImage.fileHeader = colorImage.fileHeader;
    greyImage.infoHeader = colorImage.infoHeader;
    greyImage.infoHeader.biBitcount = 8; // 灰度图每像素1字节
    long newLineBytes = (width * 8 + 31) / 32 * 4;
    greyImage.infoHeader.biSizeImage = newLineBytes * height;
    greyImage.fileHeader.bfOffBits = 1024 + 40 + 14;
    greyImage.fileHeader.bfSize = greyImage.infoHeader.biSizeImage + greyImage.fileHeader.bfOffBits;

    // 创建调色板（灰度色）
    for (int i = 0; i < 256; i++) {
        greyImage.palette[i].rgbBlue = i;     // 蓝色分量
        greyImage.palette[i].rgbGreen = i;    // 绿色分量
        greyImage.palette[i].rgbRed = i;      // 红色分量
    }

    // 为灰度图像数据分配内存并初始化为0
    greyImage.imgData = (unsigned char *) malloc(greyImage.infoHeader.biSizeImage);
    if (!greyImage.imgData) {
        printf("内存分配失败！\n");
        return;
    }
    memset(greyImage.imgData, 0, greyImage.infoHeader.biSizeImage);

    // 读取原始图像数据
    fseek(fp, colorImage.fileHeader.bfOffBits, SEEK_SET); // 移动到像素数据部分
    unsigned char *colorImageData = (unsigned char *) malloc(colorImage.infoHeader.biSizeImage);
    fread(colorImageData, colorImage.infoHeader.biSizeImage, 1, fp);
    fclose(fp);

    // 转换彩色图像为灰度图像
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // 计算灰度值并存储
            greyImage.imgData[newLineBytes * i + j] = colorImageData[lineBytes * i + j * 3] * 0.299 +
                                                      colorImageData[lineBytes * i + j * 3 + 1] * 0.587 +
                                                      colorImageData[lineBytes * i + j * 3 + 2] * 0.114;
        }
    }

    // 写入灰度图像到新文件
    FILE *outputFile = fopen("greyOutput.bmp", "wb");
    if (!outputFile) {
        printf("无法创建输出文件！\n");
        return;
    }
    fwrite(&greyImage.fileHeader, sizeof(greyImage.fileHeader), 1, outputFile);
    fwrite(&greyImage.infoHeader, sizeof(greyImage.infoHeader), 1, outputFile);
    fwrite(&greyImage.palette, 1024, 1, outputFile); // 256色，每色4字节，总共1024字节
    fwrite(greyImage.imgData, sizeof(unsigned char) * greyImage.infoHeader.biSizeImage, 1, outputFile);
    fclose(outputFile); // 关闭文件
    free(greyImage.imgData);
    free(colorImageData);

    printf("Done!");
}

//void color2grey(struct BMP colorImage, FILE *fp) {
//    struct BMP image;
//    FILE *newFp;
//    newFp = fopen("..\\..\\BMPtest\\greyOutput.BMP", "wb");
//    if (newFp == NULL) {
//        printf("Failed to create the new fileHeader!");
//    }
//    fwrite(&colorImage.fileHeader, sizeof(colorImage.fileHeader), 1, newFp);
//    fwrite(&colorImage.infoHeader, sizeof(colorImage.infoHeader), 1, newFp);
//
//    long fileWidth = colorImage.infoHeader.biWidth;
//    long fileHeight = colorImage.infoHeader.biHeight;
//    int bytesPerLine = (fileWidth * colorImage.infoHeader.biBitcount + 31) / 32 * 4;//处理每行字节数，使之为4的倍数
//    int padding = bytesPerLine - fileWidth * 3;//补位数是处理后的字节数减去原本的字节数
//    unsigned char grayInfo = 0, pixel[3] = {0};
//    for (int i = 0; i < fileHeight; i++) {
//        for (int j = 0; j < fileWidth; j++) {
//            fread(&pixel, sizeof(unsigned char), 3, fp);
//            grayInfo = (pixel[0] + pixel[1] + pixel[2]) / 3;
//            //灰度图中RGB的值相同
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//        }
//        unsigned char pad = 0;
//        for (int j = 0; j < padding; j++) {//处理补位
//            fwrite(&pad, sizeof(unsigned char), 1, newFp);
//            fseek(fp, 1, SEEK_CUR);
//        }
//    }
//    fclose(fp);
//    fclose(newFp);
//}


