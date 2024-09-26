#include <stdio.h>
#include <stdlib.h>

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
    long biSizeImage;              //λͼ�Ĵ�С�����ֽ�Ϊ��λ
    long biXPelsPermeter;       //λͼˮƽ�ֱ��ʣ�ÿ��������
    long biYPelsPermeter;       //λͼ��ֱ�ֱ��ʣ�ÿ��������
    long biClrUsed;            //λͼʵ��ʹ�õ���ɫ���е���ɫ��
    long biClrImportant;       //λͼ��ʾ��������Ҫ����ɫ��
};

struct bmp {
    struct BITMAPFILEHEADER file; //�ļ���Ϣ��
    struct BITMAPINFOHEADER info; //ͼ����Ϣ��
};

struct bmp readBmpImage(void); //��������
struct bmp color2grey(void); //��������

int main(void) {
    struct bmp testImage;          //����һ���ṹ����
    testImage = readBmpImage(); //��ȡһ��λͼ
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
    struct bmp image;        //����һ��λͼ�ṹ
    FILE *fp;
    if ((fp = fopen("d:\\CLion Project\\BMPtest\\BlackMythScreenshotBmpTest.bmp", "r")) == NULL) {
        printf("can't open the bmp imgae.\n ");
        exit(0);
    } else {
        fread(&image.file.bfType, sizeof(char), 1, fp);
        printf("����Ϊ%c", image.file.bfType);
        fread(&image.file.bfType, sizeof(char), 1, fp);
        printf("%c\n", image.file.bfType);
        fread(&image.file.bfSize, sizeof(long), 1, fp);
        printf("�ļ�����Ϊ%d\n", image.file.bfSize);
        fread(&image.file.bfReserverd1, sizeof(short int), 1, fp);
        printf("������1Ϊ%d\n", image.file.bfReserverd1);
        fread(&image.file.bfReserverd2, sizeof(short int), 1, fp);
        printf("������2Ϊ%d\n", image.file.bfReserverd2);
        fread(&image.file.bfOffBits, sizeof(long), 1, fp);
        printf("ƫ����Ϊ%d\n", image.file.bfOffBits);
        fread(&image.info.biSize, sizeof(long), 1, fp);
        printf("�˽ṹ��СΪ%d\n", image.info.biSize);
        fread(&image.info.biWidth, sizeof(long), 1, fp);
        printf("λͼ�Ŀ��Ϊ%d\n", image.info.biWidth);
        fread(&image.info.biHeight, sizeof(long), 1, fp);
        printf("λͼ�ĸ߶�Ϊ%d\n", image.info.biHeight);
        fread(&image.info.biPlanes, sizeof(short), 1, fp);
        printf("Ŀ���豸λͼ��%d\n", image.info.biPlanes);
        fread(&image.info.biBitcount, sizeof(short), 1, fp);
        printf("��ɫ���Ϊ%d\n", image.info.biBitcount);
        fread(&image.info.biCompression, sizeof(long), 1, fp);
        printf("λͼѹ������%d\n", image.info.biCompression);
        fread(&image.info.biSizeImage, sizeof(long), 1, fp);
        printf("λͼ��С%d\n", image.info.biSizeImage);
        fread(&image.info.biXPelsPermeter, sizeof(long), 1, fp);
        printf("λͼˮƽ�ֱ���Ϊ%d\n", image.info.biXPelsPermeter);
        fread(&image.info.biYPelsPermeter, sizeof(long), 1, fp);
        printf("λͼ��ֱ�ֱ���Ϊ%d\n", image.info.biYPelsPermeter);
        fread(&image.info.biClrUsed, sizeof(long), 1, fp);
        printf("λͼʵ��ʹ����ɫ��%d\n", image.info.biClrUsed);
        fread(&image.info.biClrImportant, sizeof(long), 1, fp);
        printf("λͼ��ʾ�бȽ���Ҫ��ɫ��%d\n", image.info.biClrImportant);
    }
    return image;
}
