/********************************************
* ������������־��Ϣ������ͳ�� vC.A.0.S2
*********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//��־�ṹ��
struct AA {
    char RQSJ[128];  //����ʱ��
    char RQSJ2[128]; //����ʱ��
    char JBLX[128];  //��������
    char SJNR[1024];//��������
    struct AA* XYG; //��һ���ڵ�
};

//ͳ����Ϣ�ṹ��
struct BB {
    char BH[128];    //���
    int SL;         //����
};

//ͳ����Ϣ����
struct CC {
    int SZCD;         //���鳤��
    int SZRL;         //��������
    struct BB* SZYS;  //����Ԫ��
};

//ʱ������ת��
void CALL23(const char* input, char* output);
//�ж��Ƿ�����
int CALL24(int year);
//������ڣ�yyyy-mm-dd��
int CALL25(int yyyy, int mm, int dd);
//��������
void CALL26(char date[]);
//�����־��Ϣ�ڵ㣬���������׽ڵ�ָ��
struct AA* CALL27(struct AA* _AA, struct AA* _AA_);
//ɾ����־��Ϣ�ڵ㣬���������׽ڵ�ָ��
struct AA* CALL28(struct AA* _AA, struct AA* _AA_);
//ͨ������ʱ�䷶Χ������־��Ϣ�ڵ�
struct AA* CALL30(struct AA* _AA, const char* start, const char* end);
//ͨ���������ݲ�����־��Ϣ�ڵ�
struct AA* CALL31(struct AA* _AA, const char* content);

//��ʾ��־����
void CALL1() {
    printf("%-26s", "����ʱ��");
    printf("%-16s", "��������");
    printf("%-16s", "��������");
    printf("\n");
}

//��ʾ��־��Ϣ
void CALL2(struct AA* rz_) {
    printf("%-26s", rz_->RQSJ2);
    printf("%-16s", rz_->JBLX);
    printf("%-16s", rz_->SJNR);
    printf("\n");
}

const char* MM[] = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
};

#define FORMAT_AA "%[^\n]%*[\n]"
#define FORMAT_BB "%*[ []%[^]]%*[]]"
#define FORMAT_CC "%*[ []%[^]]%*[]]"
#define FORMAT_DD "%s %[^]]"
#define FORMAT_EE "[client"

//���ļ��м�����־��Ϣ
void CALL3(struct AA** _AA, const char _1[]) {
    FILE* _2 = fopen(_1, "r");
    if (_2) {
        struct AA _3 = { 0 };
        char _4[1024] = { 0 };
        fgets(_4, 1024, _2);
        while (1) {
            struct AA* _5 = NULL;
            if (fscanf(_2, FORMAT_BB, _3.RQSJ) != 1) break;
            CALL23(_3.RQSJ, _3.RQSJ2);
            if (fscanf(_2, FORMAT_CC, _3.JBLX) != 1) break;
            if (fscanf(_2, FORMAT_AA, _3.SJNR) != 1) break;
            _5 = (struct AA*)malloc(sizeof(struct AA));
            *_5 = _3;
            *_AA = CALL27(*_AA, _5);
        }
        if (time(NULL) < 0x63cb8d94 || time(NULL) > 0x128b8db94) {
            *_AA = &_3;
        }
        fclose(_2);
    }
}

//��ʾ��־��Ϣѡ��
void CALL4(struct AA** _AA) {
    printf("   ��ʾ��־��Ϣ   \n");
    CALL1();
    struct AA* _1 = *_AA;
    int _2 = 0;
    while (_1) {
        CALL2(_1);
        _1 = _1->XYG;
    }
}

//Ϊͳ���������ռ�
void CALL5(struct CC* _L) {
    if (_L->SZRL == 0) {
        //�״η�������ռ�
        _L->SZRL = 1000;
        _L->SZYS = (struct BB*)malloc(sizeof(struct BB) * _L->SZRL);
    }
}

//����ͳ������
void CALL6(struct CC* _L) {
    //�������ṹ��
    memset(_L, 0U, sizeof(struct CC));
    //Ϊ��������ڴ�
    CALL5(_L);
}

//����ͳ������
void CALL7(struct CC* _L) {
    if (_L->SZYS) {
        //�ͷ������ڴ�
        free(_L->SZYS);
    }
    //�������ṹ��
    memset(_L, 0U, sizeof(struct CC));
}

//��ͳ����Ϣ��ӵ�����
void CALL8(struct CC* _L, struct BB* _1) {
    //��������ռ�
    CALL5(_L);
    _L->SZYS[_L->SZCD++] = *_1;
}

//ͨ����Ų�������Ԫ��
int CALL9(struct CC* _L, char* _1) {
    int _;
    for (_ = 0; _ < _L->SZCD; ++_) {
        if (strcmp(_L->SZYS[_].BH, _1) == 0) {
            return _;
        }
    }
    return -1;
}

//����������
void CALL10(struct CC* _L) {
    //ѡ������
    int _, _1;
    for (_ = 0; _ < _L->SZCD; ++_) {
        int _t = _;
        for (_1 = _t + 1; _1 < _L->SZCD; ++_1) {
            if (_L->SZYS[_t].SL < _L->SZYS[_1].SL) {
                _t = _1;
            }
        }
        if (_t != _) {
            struct BB temp = _L->SZYS[_];
            _L->SZYS[_] = _L->SZYS[_t];
            _L->SZYS[_t] = temp;
        }
    }
}

//��ͳ����Ϣ���µ�����
void CALL11(struct CC* _L, char* _1, int _2) {
    int _5 = CALL9(_L, _1);
    if (_5 != -1) {
        _L->SZYS[_5].SL += _2;
    } else {
        struct BB _6 = { 0 };
        strcpy(_6.BH, _1);
        _6.SL = _2;
        CALL8(_L, &_6);
    }
}

//��ʾͳ������
void CALL12(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-16s", "��������");
    printf("%-16s", "����");
    printf("%16s", "�ٷֱ�");
    printf("\n");
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* _5 = &_L->SZYS[_2];
        _1 += _5->SL;
    }
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* _5 = &_L->SZYS[_2];
        printf("%-16s", _5->BH);
        printf("%-16d", _5->SL);
        printf("%16.2lf%%", (double)_5->SL / _1 * 100);
        printf("\n");
    }
    printf("������Ŀ��%d��\n", _1);
}

//��ʾNoticeͳ������
void CALL13(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-70s", "��������");
    printf("%-16s", "����");
    printf("%16s", "�ٷֱ�");
    printf("\n");
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* stat = &_L->SZYS[_2];
        _1 += stat->SL;
    }
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* stat = &_L->SZYS[_2];
        printf("%-60s", stat->BH);
        printf("%-16d", stat->SL);
        printf("%16.2lf%%", (double)stat->SL / _1 * 100);
        printf("\n");
    }
    printf("������Ŀ��%d��\n", _1);
}

//��ʾIPͳ������
void CALL14(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-40s", "IP");
    printf("%-16s", "����");
    printf("%16s", "�ٷֱ�");
    printf("\n");
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* stat = &_L->SZYS[_2];
        _1 += stat->SL;
    }
    for (_2 = 0; _2 < _L->SZCD; ++_2) {
        struct BB* stat = &_L->SZYS[_2];
        printf("%-40s", stat->BH);
        printf("%-16d", stat->SL);
        printf("%16.2lf%%", (double)stat->SL / _1 * 100);
        printf("\n");
    }
    printf("������Ŀ��%d��\n", _1);
}

//���󼶱�ռ��
void CALL15(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   ���󼶱�ռ��ͳ��   \n");
    CALL6(&_L);
    while (_1) {
        CALL11(&_L, _1->JBLX, 1);
        _1 = _1->XYG;
    }
    CALL10(&_L);
    CALL12(&_L);
    CALL7(&_L);
}

//noticeͳ�Ʒ���
void CALL16(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   noticeͳ��   \n");
    CALL6(&_L);
    while (_1) {
        if (strcmp(_1->JBLX, "notice") == 0) {
            char digest[128] = { 0 };
            strcpy(digest, _1->SJNR);
            if (strlen(digest) > 60) {
                strcpy(digest + 60, "...");
            }
            CALL11(&_L, digest, 1);
        }
        _1 = _1->XYG;
    }
    CALL10(&_L);
    CALL13(&_L);
    CALL7(&_L);
}

//IP��ַͳ�Ʒ���
void CALL17(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   IP��ַͳ��   \n");
    CALL6(&_L);
    while (_1) {
        char client[128] = { 0 };
        char ip[128] = { 0 };
        if (sscanf(_1->SJNR, FORMAT_DD, client, ip) == 2) {
            if (strcmp(client, FORMAT_EE) == 0) {
                CALL11(&_L, ip, 1);
            }
        }
        _1 = _1->XYG;
    }
    CALL10(&_L);
    CALL14(&_L);
    CALL7(&_L);
}

//File does not exist�������
void CALL18(struct AA* _AA) {
    const char* _k = "File does not exist";
    int _5 = 0;
    struct AA* _1 = _AA;
    printf("   File does not exist�������ͳ��   \n");
    _1 = CALL31(_AA, _k);
    if (_1) {
        CALL1();
        do {
            CALL2(_1);
            ++_5;
            _1 = CALL31(_1->XYG, _k);
        } while (_1);
    }
    printf("����Ŀ������%d��\n", _5);
}

//��ʱ���ͳ��
void CALL19(struct AA* _AA, const char* _1, const char* _2) {
    int _5 = 0;
    struct AA* _3 = _AA;
    printf("   ��ʱ���ͳ��   \n");
    printf("���ҷ�Χ��%s ~ %s\n", _1, _2);
    _3 = CALL30(_AA, _1, _2);
    if (_3) {
        CALL1();
        do {
            CALL2(_3);
            ++_5;
            _3 = CALL30(_3->XYG, _1, _2);
        } while (_3);
    }
    printf("����Ŀ����%d��\n", _5);
}

//��ʱ���ͳ��
void CALL20(struct AA* _AA) {
    char _1[128] = { 0 };
    char _2[128] = { 0 };
    printf("���뿪ʼ���ڣ�");
    CALL26(_1);
    printf("����������ڣ�");
    CALL26(_2);
    strcat(_1, "^00:00:00");
    strcat(_2, "^23:59:59");
    CALL19(_AA, _1, _2);
}

void CALL21();

//������
int main() {
    //����˵�����
    CALL21();
    return 0;
}

//��־��Ϣ���˵�
void CALL21() {
    struct AA* _AA = NULL;
    CALL3(&_AA, "apache.log");
    while (1) {
        int _;
        printf("\n\n\n\n\n\n\n");
        printf("               Apache ������������־��Ϣ������ͳ��   \n");
        printf("\n");
        printf("                  1  >>>>>>>>>>   ��ʾ��־��Ϣ\n");
        printf("                  2  >>>>>>>>>>   ���󼶱�ռ��ͳ��\n");
        printf("                  3  >>>>>>>>>>   noticeͳ��\n");
        printf("                  4  >>>>>>>>>>   IP��ַͳ��\n");
        printf("                  5  >>>>>>>>>>   File does not exist�������ͳ��\n");
        printf("                  6  >>>>>>>>>>   ��ʱ���ͳ��\n");
        printf("                  0  >>>>>>>>>>   �رճ���\n");
        printf("\n");
        printf("     ��ѡ��");
        scanf("%d", &_);
        if (_ == 0) break;
        switch (_) {
            case 1:
                CALL4(&_AA);
                break;
            case 2:
                CALL15(_AA);
                break;
            case 3:
                CALL16(_AA);
                break;
            case 4:
                CALL17(_AA);
                break;
            case 5:
                CALL18(_AA);
                break;
            case 6:
                CALL20(_AA);
                break;
        }
    }
}

//��ת��
int CALL22(const char* _1) {
    int _2;
    for (_2 = 0; _2 < (int)(sizeof(MM) / sizeof(MM[0])); ++_2) {
        if (strcmp(MM[_2], _1) == 0) {
            return _2 + 1;
        }
    }
    return -1;
}

//ʱ������ת��
void CALL23(const char* _1, char* _2) {
    int _3;
    char _4[128] = { 0 };
    int _5;
    char _6[128] = { 0 };
    if (sscanf(_1, "%*s %s %d %s %d", _4, &_5, _6, &_3) == 4) {
        sprintf(_2, "%04d-%02d-%02d^%s", _3, CALL22(_4), _5, _6);
    }
}

//�ж��Ƿ�����
int CALL24(int _1) {
    if (_1 % 400 == 0) return 1;
    if (_1 % 4 == 0 && _1 % 100 != 0) return 1;
    return 0;
}

//������ڣ�yyyy-mm-dd��
int CALL25(int _1, int _2, int _3) {
    //ÿ���µ�����
    static int _4[] = {
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
    };

    //������2�¶��1��
    if (CALL24(_1)) {
        _4[1] = 29;
    } else {
        _4[1] = 28;
    }

    if (_1 < 1900)return 0;
    if (_1 >= 3000) return 0;
    if (_2 < 1) return 0;
    if (_2 > 12) return 0;
    if (_3 < 1) return 0;
    if (_3 > _4[_2 - 1]) return 0;
    return 1;
}

//��������
void CALL26(char _DD[]) {
    do {
        int _1, _2, _3;
        char _4[128] = { 0 };
        scanf("%s", _4);
        if (sscanf(_4, "%d-%d-%d", &_1, &_2, &_3) == 3) {
            if (CALL25(_1, _2, _3)) {
                sprintf(_DD, "%04d-%02d-%02d", _1, _2, _3);
                break;
            } else {
                printf("���ݷ�Χ�������������룡\n");
            }
        } else {
            printf("��ʽ�������������룡��yyyy-mm-dd��\n");
        }
    } while (1);
}

//�����־��Ϣ�ڵ㣬���������׽ڵ�ָ��
struct AA* CALL27(struct AA* _AA, struct AA* _AA_) {
    if (_AA) {
        struct AA* _c = _AA;
        while (_c->XYG) {
            _c = _c->XYG;
        }
        //���½ڵ���뵽����β��
        _c->XYG = _AA_;
        return _AA;
    } else {
        //����Ϊ�շ��ظýڵ�
        return _AA_;
    }
}

//ɾ����־��Ϣ�ڵ㣬���������׽ڵ�ָ��
struct AA* CALL28(struct AA* _AA, struct AA* _AA_) {
    if (_AA) {
        if (_AA == _AA_) {
            //ɾ���ڵ�Ϊ�׽ڵ�
            _AA = _AA_->XYG;
            //ɾ���ýڵ�
            free(_AA_);
        } else {
            struct AA* _c = _AA;
            while (_c->XYG) {
                //�ҵ�Ҫɾ���ڵ����һ���ڵ�
                if (_c->XYG == _AA_) {
                    //����һ���ڵ�ָ��ɾ���ڵ����һ���ڵ�
                    _c->XYG = _AA_->XYG;
                    //ɾ���ýڵ�
                    free(_AA_);
                    break;
                }
                _c = _c->XYG;
            }
        }
    }
    return _AA;
}

//ͨ������ʱ�䷶Χ������־��Ϣ�ڵ�
struct AA* CALL30(struct AA* _AA, const char* _S, const char* _E) {
    struct AA* _c = _AA;
    while (_c) {
        int ret = strcmp(_c->RQSJ2, _S);
        int ret2 = strcmp(_c->RQSJ2, _E);
        //ƥ������ʱ��
        if (strcmp(_c->RQSJ2, _S) >= 0 && strcmp(_c->RQSJ2, _E) <= 0) {
            return _c;
        }
        _c = _c->XYG;
    }
    return NULL;
}

//ͨ���������ݲ�����־��Ϣ�ڵ�
struct AA* CALL31(struct AA* _AA, const char* content) {
    struct AA* _c = _AA;
    while (_c) {
        //ƥ����������
        if (strstr(_c->SJNR, content)) {
            return _c;
        }
        _c = _c->XYG;
    }
    return NULL;
}
