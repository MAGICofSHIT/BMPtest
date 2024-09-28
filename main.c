#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BITMAPFILEHEADER {
    unsigned short int bfType;       //λͼ�ļ������ͣ�����ΪBM
    unsigned long bfSize;       //�ļ���С�����ֽ�Ϊ��λ
    unsigned short int bfReserverd1; //λͼ�ļ������֣�����Ϊ0
    unsigned short int bfReserverd2; //λͼ�ļ������֣�����Ϊ0
    unsigned long bfOffBits;  //λͼ�ļ�ͷ�����ݵ�ƫ���������ֽ�Ϊ��λ
};

struct BITMAPINFOHEADER {
    long biSize;                        //�ýṹ��С���ֽ�Ϊ��λ
    long biWidth;                     //ͼ�ο��������Ϊ��λ
    long biHeight;                     //ͼ�θ߶�������Ϊ��λ
    short int biPlanes;               //Ŀ���豸�ļ��𣬱���Ϊ1
    short int biBitcount;             //��ɫ��ȣ�ÿ����������Ҫ��λ��
    short int biCompression;        //λͼ��ѹ������
    long biSizeImage;              //ͼ�����ݵĴ�С�����ֽ�Ϊ��λ
    long biXPelsPermeter;       //λͼˮƽ�ֱ��ʣ�ÿ��������
    long biYPelsPermeter;       //λͼ��ֱ�ֱ��ʣ�ÿ��������
    long biClrUsed;            //λͼʵ��ʹ�õ���ɫ���е���ɫ��
    long biClrImportant;       //λͼ��ʾ��������Ҫ����ɫ��
};

// ����RGB��ɫ��ṹ
struct RGBQUAD {
    unsigned char rgbBlue;         // ��ɫ����
    unsigned char rgbGreen;        // ��ɫ����
    unsigned char rgbRed;          // ��ɫ����
    unsigned char rgbReserved;     // �����֣�ͨ��Ϊ0
};

struct BMP {
    struct BITMAPFILEHEADER fileHeader; //�ļ���Ϣ��
    struct BITMAPINFOHEADER infoHeader; //ͼ����Ϣ��
    struct RGBQUAD palette[256];        //��ɫ�壬���256ɫ
    unsigned char *imgData;             //ָ��ͼ�����ݵ�ָ��
};

struct BMP readBmpImage(struct BMP originalImage,FILE **fp);

void color2grey(struct BMP colorImage, FILE *fp);

int main() {
    struct BMP originalImage;          //����һ���ṹ����
    FILE *Fp;
    struct BMP colorImage = readBmpImage(originalImage,&Fp); //��ȡһ��λͼ
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
        printf("����Ϊ%c", originalImage.fileHeader.bfType);
        fread(&originalImage.fileHeader.bfType, sizeof(char), 1, *fp);
        printf("%c\n", originalImage.fileHeader.bfType);
        fread(&originalImage.fileHeader.bfSize, sizeof(long), 1, *fp);
        printf("�ļ�����Ϊ%d\n", originalImage.fileHeader.bfSize);
        fread(&originalImage.fileHeader.bfReserverd1, sizeof(short int), 1, *fp);
        printf("������1Ϊ%d\n", originalImage.fileHeader.bfReserverd1);
        fread(&originalImage.fileHeader.bfReserverd2, sizeof(short int), 1, *fp);
        printf("������2Ϊ%d\n", originalImage.fileHeader.bfReserverd2);
        fread(&originalImage.fileHeader.bfOffBits, sizeof(long), 1, *fp);
        printf("ƫ����Ϊ%d\n", originalImage.fileHeader.bfOffBits);
        fread(&originalImage.infoHeader.biSize, sizeof(long), 1, *fp);
        printf("�˽ṹ��СΪ%d\n", originalImage.infoHeader.biSize);
        fread(&originalImage.infoHeader.biWidth, sizeof(long), 1, *fp);
        printf("λͼ�Ŀ��Ϊ%d\n", originalImage.infoHeader.biWidth);
        fread(&originalImage.infoHeader.biHeight, sizeof(long), 1, *fp);
        printf("λͼ�ĸ߶�Ϊ%d\n", originalImage.infoHeader.biHeight);
        fread(&originalImage.infoHeader.biPlanes, sizeof(short), 1, *fp);
        printf("Ŀ���豸λͼ��%d\n", originalImage.infoHeader.biPlanes);
        fread(&originalImage.infoHeader.biBitcount, sizeof(short), 1, *fp);
        printf("��ɫ���Ϊ%d\n", originalImage.infoHeader.biBitcount);
        fread(&originalImage.infoHeader.biCompression, sizeof(long), 1, *fp);
        printf("λͼѹ������%d\n", originalImage.infoHeader.biCompression);
        fread(&originalImage.infoHeader.biSizeImage, sizeof(long), 1, *fp);
        printf("λͼ��С%d\n", originalImage.infoHeader.biSizeImage);
        fread(&originalImage.infoHeader.biXPelsPermeter, sizeof(long), 1, *fp);
        printf("λͼˮƽ�ֱ���Ϊ%d\n", originalImage.infoHeader.biXPelsPermeter);
        fread(&originalImage.infoHeader.biYPelsPermeter, sizeof(long), 1, *fp);
        printf("λͼ��ֱ�ֱ���Ϊ%d\n", originalImage.infoHeader.biYPelsPermeter);
        fread(&originalImage.infoHeader.biClrUsed, sizeof(long), 1, *fp);
        printf("λͼʵ��ʹ����ɫ��%d\n", originalImage.infoHeader.biClrUsed);
        fread(&originalImage.infoHeader.biClrImportant, sizeof(long), 1, *fp);
        printf("λͼ��ʾ�бȽ���Ҫ��ɫ��%d\n", originalImage.infoHeader.biClrImportant);
    }
    return originalImage;
}

void color2grey(struct BMP colorImage, FILE *fp) {
    long width = colorImage.infoHeader.biWidth;
    long height = colorImage.infoHeader.biHeight;
    long lineBytes = (width * colorImage.infoHeader.biBitcount + 31) / 32 * 4;

    // �����Ҷ�ͼ�ṹ������ͷ�ļ�����Ӧ�Ҷ�ͼ
    struct BMP greyImage;
    greyImage.fileHeader = colorImage.fileHeader;
    greyImage.infoHeader = colorImage.infoHeader;
    greyImage.infoHeader.biBitcount = 8; // �Ҷ�ͼÿ����1�ֽ�
    long newLineBytes = (width * 8 + 31) / 32 * 4;
    greyImage.infoHeader.biSizeImage = newLineBytes * height;
    greyImage.fileHeader.bfOffBits = 1024 + 40 + 14;
    greyImage.fileHeader.bfSize = greyImage.infoHeader.biSizeImage + greyImage.fileHeader.bfOffBits;

    // ������ɫ�壨�Ҷ�ɫ��
    for (int i = 0; i < 256; i++) {
        greyImage.palette[i].rgbBlue = i;     // ��ɫ����
        greyImage.palette[i].rgbGreen = i;    // ��ɫ����
        greyImage.palette[i].rgbRed = i;      // ��ɫ����
    }

    // Ϊ�Ҷ�ͼ�����ݷ����ڴ沢��ʼ��Ϊ0
    greyImage.imgData = (unsigned char *) malloc(greyImage.infoHeader.biSizeImage);
    if (!greyImage.imgData) {
        printf("�ڴ����ʧ�ܣ�\n");
        return;
    }
    memset(greyImage.imgData, 0, greyImage.infoHeader.biSizeImage);

    // ��ȡԭʼͼ������
    fseek(fp, colorImage.fileHeader.bfOffBits, SEEK_SET); // �ƶ����������ݲ���
    unsigned char *colorImageData = (unsigned char *) malloc(colorImage.infoHeader.biSizeImage);
    fread(colorImageData, colorImage.infoHeader.biSizeImage, 1, fp);
    fclose(fp);

    // ת����ɫͼ��Ϊ�Ҷ�ͼ��
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // ����Ҷ�ֵ���洢
            greyImage.imgData[newLineBytes * i + j] = colorImageData[lineBytes * i + j * 3] * 0.299 +
                                                      colorImageData[lineBytes * i + j * 3 + 1] * 0.587 +
                                                      colorImageData[lineBytes * i + j * 3 + 2] * 0.114;
        }
    }

    // д��Ҷ�ͼ�����ļ�
    FILE *outputFile = fopen("greyOutput.bmp", "wb");
    if (!outputFile) {
        printf("�޷���������ļ���\n");
        return;
    }
    fwrite(&greyImage.fileHeader, sizeof(greyImage.fileHeader), 1, outputFile);
    fwrite(&greyImage.infoHeader, sizeof(greyImage.infoHeader), 1, outputFile);
    fwrite(&greyImage.palette, 1024, 1, outputFile); // 256ɫ��ÿɫ4�ֽڣ��ܹ�1024�ֽ�
    fwrite(greyImage.imgData, sizeof(unsigned char) * greyImage.infoHeader.biSizeImage, 1, outputFile);
    fclose(outputFile); // �ر��ļ�
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
//    int bytesPerLine = (fileWidth * colorImage.infoHeader.biBitcount + 31) / 32 * 4;//����ÿ���ֽ�����ʹ֮Ϊ4�ı���
//    int padding = bytesPerLine - fileWidth * 3;//��λ���Ǵ������ֽ�����ȥԭ�����ֽ���
//    unsigned char grayInfo = 0, pixel[3] = {0};
//    for (int i = 0; i < fileHeight; i++) {
//        for (int j = 0; j < fileWidth; j++) {
//            fread(&pixel, sizeof(unsigned char), 3, fp);
//            grayInfo = (pixel[0] + pixel[1] + pixel[2]) / 3;
//            //�Ҷ�ͼ��RGB��ֵ��ͬ
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//            fwrite(&grayInfo, sizeof(unsigned char), 1, newFp);
//        }
//        unsigned char pad = 0;
//        for (int j = 0; j < padding; j++) {//����λ
//            fwrite(&pad, sizeof(unsigned char), 1, newFp);
//            fseek(fp, 1, SEEK_CUR);
//        }
//    }
//    fclose(fp);
//    fclose(newFp);
//}


