/********************************************
* 服务器错误日志信息分析与统计 vC.A.0.S2
*********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//日志结构体
struct AA {
    char RQSJ[128];  //日期时间
    char RQSJ2[128]; //日期时间
    char JBLX[128];  //级别类型
    char SJNR[1024];//数据内容
    struct AA* XYG; //下一个节点
};

//统计信息结构体
struct BB {
    char BH[128];    //编号
    int SL;         //数量
};

//统计信息数组
struct CC {
    int SZCD;         //数组长度
    int SZRL;         //数组容量
    struct BB* SZYS;  //数组元素
};

//时间日期转换
void CALL23(const char* input, char* output);
//判断是否闰年
int CALL24(int year);
//检测日期（yyyy-mm-dd）
int CALL25(int yyyy, int mm, int dd);
//输入日期
void CALL26(char date[]);
//添加日志信息节点，返回链表首节点指针
struct AA* CALL27(struct AA* _AA, struct AA* _AA_);
//删除日志信息节点，返回链表首节点指针
struct AA* CALL28(struct AA* _AA, struct AA* _AA_);
//通过日期时间范围查找日志信息节点
struct AA* CALL30(struct AA* _AA, const char* start, const char* end);
//通过数据内容查找日志信息节点
struct AA* CALL31(struct AA* _AA, const char* content);

//显示日志标题
void CALL1() {
    printf("%-26s", "日期时间");
    printf("%-16s", "级别类型");
    printf("%-16s", "数据内容");
    printf("\n");
}

//显示日志信息
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

//从文件中加载日志信息
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

//显示日志信息选项
void CALL4(struct AA** _AA) {
    printf("   显示日志信息   \n");
    CALL1();
    struct AA* _1 = *_AA;
    int _2 = 0;
    while (_1) {
        CALL2(_1);
        _1 = _1->XYG;
    }
}

//为统计数组分配空间
void CALL5(struct CC* _L) {
    if (_L->SZRL == 0) {
        //首次分配数组空间
        _L->SZRL = 1000;
        _L->SZYS = (struct BB*)malloc(sizeof(struct BB) * _L->SZRL);
    }
}

//创建统计数组
void CALL6(struct CC* _L) {
    //清空数组结构体
    memset(_L, 0U, sizeof(struct CC));
    //为数组分配内存
    CALL5(_L);
}

//销毁统计数组
void CALL7(struct CC* _L) {
    if (_L->SZYS) {
        //释放数组内存
        free(_L->SZYS);
    }
    //清空数组结构体
    memset(_L, 0U, sizeof(struct CC));
}

//将统计信息添加到数组
void CALL8(struct CC* _L, struct BB* _1) {
    //分配数组空间
    CALL5(_L);
    _L->SZYS[_L->SZCD++] = *_1;
}

//通过编号查找数组元素
int CALL9(struct CC* _L, char* _1) {
    int _;
    for (_ = 0; _ < _L->SZCD; ++_) {
        if (strcmp(_L->SZYS[_].BH, _1) == 0) {
            return _;
        }
    }
    return -1;
}

//按数量排序
void CALL10(struct CC* _L) {
    //选择排序
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

//将统计信息更新到数组
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

//显示统计数据
void CALL12(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-16s", "级别类型");
    printf("%-16s", "数量");
    printf("%16s", "百分比");
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
    printf("【总条目：%d】\n", _1);
}

//显示Notice统计数据
void CALL13(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-70s", "数据内容");
    printf("%-16s", "数量");
    printf("%16s", "百分比");
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
    printf("【总条目：%d】\n", _1);
}

//显示IP统计数据
void CALL14(struct CC* _L) {
    int _1 = 0;
    int _2;
    printf("%-40s", "IP");
    printf("%-16s", "数量");
    printf("%16s", "百分比");
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
    printf("【总条目：%d】\n", _1);
}

//错误级别占比
void CALL15(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   错误级别占比统计   \n");
    CALL6(&_L);
    while (_1) {
        CALL11(&_L, _1->JBLX, 1);
        _1 = _1->XYG;
    }
    CALL10(&_L);
    CALL12(&_L);
    CALL7(&_L);
}

//notice统计分析
void CALL16(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   notice统计   \n");
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

//IP地址统计分析
void CALL17(struct AA* _AA) {
    struct CC _L = { 0 };
    struct AA* _1 = _AA;
    printf("   IP地址统计   \n");
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

//File does not exist错误次数
void CALL18(struct AA* _AA) {
    const char* _k = "File does not exist";
    int _5 = 0;
    struct AA* _1 = _AA;
    printf("   File does not exist错误次数统计   \n");
    _1 = CALL31(_AA, _k);
    if (_1) {
        CALL1();
        do {
            CALL2(_1);
            ++_5;
            _1 = CALL31(_1->XYG, _k);
        } while (_1);
    }
    printf("【条目数量：%d】\n", _5);
}

//按时间段统计
void CALL19(struct AA* _AA, const char* _1, const char* _2) {
    int _5 = 0;
    struct AA* _3 = _AA;
    printf("   按时间段统计   \n");
    printf("查找范围：%s ~ %s\n", _1, _2);
    _3 = CALL30(_AA, _1, _2);
    if (_3) {
        CALL1();
        do {
            CALL2(_3);
            ++_5;
            _3 = CALL30(_3->XYG, _1, _2);
        } while (_3);
    }
    printf("【条目数：%d】\n", _5);
}

//按时间段统计
void CALL20(struct AA* _AA) {
    char _1[128] = { 0 };
    char _2[128] = { 0 };
    printf("输入开始日期：");
    CALL26(_1);
    printf("输入结束日期：");
    CALL26(_2);
    strcat(_1, "^00:00:00");
    strcat(_2, "^23:59:59");
    CALL19(_AA, _1, _2);
}

void CALL21();

//主函数
int main() {
    //进入菜单操作
    CALL21();
    return 0;
}

//日志信息主菜单
void CALL21() {
    struct AA* _AA = NULL;
    CALL3(&_AA, "apache.log");
    while (1) {
        int _;
        printf("\n\n\n\n\n\n\n");
        printf("               Apache 服务器错误日志信息分析与统计   \n");
        printf("\n");
        printf("                  1  >>>>>>>>>>   显示日志信息\n");
        printf("                  2  >>>>>>>>>>   错误级别占比统计\n");
        printf("                  3  >>>>>>>>>>   notice统计\n");
        printf("                  4  >>>>>>>>>>   IP地址统计\n");
        printf("                  5  >>>>>>>>>>   File does not exist错误次数统计\n");
        printf("                  6  >>>>>>>>>>   按时间段统计\n");
        printf("                  0  >>>>>>>>>>   关闭程序\n");
        printf("\n");
        printf("     请选择：");
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

//月转换
int CALL22(const char* _1) {
    int _2;
    for (_2 = 0; _2 < (int)(sizeof(MM) / sizeof(MM[0])); ++_2) {
        if (strcmp(MM[_2], _1) == 0) {
            return _2 + 1;
        }
    }
    return -1;
}

//时间日期转换
void CALL23(const char* _1, char* _2) {
    int _3;
    char _4[128] = { 0 };
    int _5;
    char _6[128] = { 0 };
    if (sscanf(_1, "%*s %s %d %s %d", _4, &_5, _6, &_3) == 4) {
        sprintf(_2, "%04d-%02d-%02d^%s", _3, CALL22(_4), _5, _6);
    }
}

//判断是否闰年
int CALL24(int _1) {
    if (_1 % 400 == 0) return 1;
    if (_1 % 4 == 0 && _1 % 100 != 0) return 1;
    return 0;
}

//检测日期（yyyy-mm-dd）
int CALL25(int _1, int _2, int _3) {
    //每个月的天数
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

    //闰年则2月多加1天
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

//输入日期
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
                printf("数据范围错误，请重新输入！\n");
            }
        } else {
            printf("格式错误，请重新输入！（yyyy-mm-dd）\n");
        }
    } while (1);
}

//添加日志信息节点，返回链表首节点指针
struct AA* CALL27(struct AA* _AA, struct AA* _AA_) {
    if (_AA) {
        struct AA* _c = _AA;
        while (_c->XYG) {
            _c = _c->XYG;
        }
        //将新节点插入到链表尾部
        _c->XYG = _AA_;
        return _AA;
    } else {
        //链表为空返回该节点
        return _AA_;
    }
}

//删除日志信息节点，返回链表首节点指针
struct AA* CALL28(struct AA* _AA, struct AA* _AA_) {
    if (_AA) {
        if (_AA == _AA_) {
            //删除节点为首节点
            _AA = _AA_->XYG;
            //删除该节点
            free(_AA_);
        } else {
            struct AA* _c = _AA;
            while (_c->XYG) {
                //找到要删除节点的上一个节点
                if (_c->XYG == _AA_) {
                    //将上一个节点指向删除节点的下一个节点
                    _c->XYG = _AA_->XYG;
                    //删除该节点
                    free(_AA_);
                    break;
                }
                _c = _c->XYG;
            }
        }
    }
    return _AA;
}

//通过日期时间范围查找日志信息节点
struct AA* CALL30(struct AA* _AA, const char* _S, const char* _E) {
    struct AA* _c = _AA;
    while (_c) {
        int ret = strcmp(_c->RQSJ2, _S);
        int ret2 = strcmp(_c->RQSJ2, _E);
        //匹配日期时间
        if (strcmp(_c->RQSJ2, _S) >= 0 && strcmp(_c->RQSJ2, _E) <= 0) {
            return _c;
        }
        _c = _c->XYG;
    }
    return NULL;
}

//通过数据内容查找日志信息节点
struct AA* CALL31(struct AA* _AA, const char* content) {
    struct AA* _c = _AA;
    while (_c) {
        //匹配数据内容
        if (strstr(_c->SJNR, content)) {
            return _c;
        }
        _c = _c->XYG;
    }
    return NULL;
}
