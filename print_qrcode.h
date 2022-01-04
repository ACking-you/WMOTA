//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_PRINT_QRCODE_H
#define WMOTA_PRINT_QRCODE_H
#define QR_CODE(PATH) void print_qrcode(){\
    FILE* fd = fopen(PATH, "r");\
    if(fd==NULL){\
        perror("fopen");\
        exit(-1);\
    }\
    char buf[1024*1024];\
    fseek(fd, 0, SEEK_END);\
    int f_size =  ftell(fd);\
    if(f_size==0){\
        perror("ftell");\
        exit(-1);}\
    fseek(fd, 0, SEEK_SET);\
    fread(buf,1,f_size,fd);\
    buf[f_size] = '\0';\
    system("cls");\
    printf("\033[7m%s",buf);\
    printf("\033[0;32;31m��ִ��������������Զ�ά�����ɨ�裺1.���ն˷Ŵ�ȫ�� 2.��סctrl+�����ֽ������� 3.���ն˻ָ���ԭ���Ĵ�С���ɿ�����ά��\033[m");\
    fclose(fd);}\



#endif //WMOTA_PRINT_QRCODE_H
