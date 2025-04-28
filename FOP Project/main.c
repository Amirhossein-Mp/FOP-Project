#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char buying[10];
    char maint[10];
    char doors[10];
    char persons[10];
    char lug_boot[10];
    char safety[10];
    char label[10];
}info;
// predicted struct
info info3[2000];
// customized struct
info info8[2000];
int tp_vgood=0;
int tp_good=0;
int tp_acc=0;
int tp_unacc=0;
int fp_vgood=0;
int fp_good=0;
int fp_acc=0;
int fp_unacc=0;
int tn_vgood=0;
int tn_good=0;
int tn_acc=0;
int tn_unacc=0;
int fn_vgood=0;
int fn_good=0;
int fn_acc=0;
int fn_unacc=0;
int k1;
int k2;
int k3;
int k4;
int i=0;
int p=0;
int nol_in_input_list=0;
int nol_in_edited_list=0;
info info1[2000];
int vgood_buying_vhigh;
int vgood_buying_high;
int vgood_buying_med;
int vgood_buying_low;
int good_buying_vhigh;
int good_buying_high;
int good_buying_med;
int good_buying_low;
int acc_buying_vhigh;
int acc_buying_high;
int acc_buying_med;
int acc_buying_low;
int vgood_maint_vhigh;
int vgood_maint_high;
int vgood_maint_med;
int vgood_maint_low;
int good_maint_vhigh;
int good_maint_high;
int good_maint_med;
int good_maint_low;
int acc_maint_vhigh;
int acc_maint_high;
int acc_maint_med;
int acc_maint_low;
int vgood_doors_more;
int vgood_doors_4;
int vgood_doors_3;
int vgood_doors_2;
int good_doors_more;
int good_doors_4;
int good_doors_3;
int good_doors_2;
int acc_doors_more;
int acc_doors_4;
int acc_doors_3;
int acc_doors_2;
int vgood_persons_more;
int vgood_persons_4;
int vgood_persons_2;
int good_persons_more;
int good_persons_4;
int good_persons_2;
int acc_persons_more;
int acc_persons_4;
int acc_persons_2;
int vgood_lug_boot_big;
int vgood_lug_boot_med;
int vgood_lug_boot_small;
int good_lug_boot_big;
int good_lug_boot_med;
int good_lug_boot_small;
int acc_lug_boot_big;
int acc_lug_boot_med;
int acc_lug_boot_small;
int vgood_safety_high;
int vgood_safety_med;
int vgood_safety_low;
int good_safety_high;
int good_safety_med;
int good_safety_low;
int acc_safety_high;
int acc_safety_med;
int acc_safety_low;
float final_number1=1;
float final_number2=1;
float final_number3=1;
float final_number4;
char input_string[200];
void classify(char lineoftext[],info info1[]);
int sort_by_result_vgood(info info1[],int y);
int sort_by_result_good(info info1[],int y,int l);
int sort_by_result_acc(info info1[],int y,int l,int r);
void matching_input_string(char input_string[],info info1[]);
void first_number_of_vgood(info info1[]);
void second_number_of_vgood(info info1[]);
void third_number_of_vgood(info info1[]);
void fourth_number_of_vgood(info info1[]);
void fifth_number_of_vgood(info info1[]);
void sixth_number_of_vgood(info info1[]);
void first_number_of_good(info info1[]);
void second_number_of_good(info info1[]);
void third_number_of_good(info info1[]);
void fourth_number_of_good(info info1[]);
void fifth_number_of_good(info info1[]);
void sixth_number_of_good(info info1[]);
void first_number_of_acc(info info1[]);
void second_number_of_acc(info info1[]);
void third_number_of_acc(info info1[]);
void fourth_number_of_acc(info info1[]);
void fifth_number_of_acc(info info1[]);
void sixth_number_of_acc(info info1[]);
void feature_1();
int comparison();
void main_list1();
void main_list2();
void classify2();
void final_result_feature_1();
void feature4();
void evaluation_vgood();
void evaluation_good();
void evaluation_acc();
void evaluation_unacc();
void check(char line_of_text[]);
int main() {
    int a=0;
    main_list1();
    int requested_feature=0;
    scanf("%d",&requested_feature);
    do {
        if(a!=0) {
            main_list2();
            scanf("%d", &requested_feature);
        }
        a++;
        if (requested_feature == 1) {
            feature_1();
        } else if (requested_feature == 2) {
            FILE *fgptr;
            fgptr = fopen("input_list.txt", "r");
            while (!feof(fgptr)) {
                char history_string[100];
                fscanf(fgptr, "%s\n\n", history_string);
                printf("%s\n", history_string);
            }
            fclose(fgptr);
        } else if (requested_feature == 3) {
            FILE *fe_ptr;
            FILE *fgptr;
            fgptr = fopen("input_list.txt", "r");
            fe_ptr = fopen("edited_list.txt", "w");
            while (!feof(fgptr)) {
                char history_string1[100];
                char history_string2[100];
                fscanf(fgptr, "%s\n", history_string1);
                strcpy(history_string2, history_string1);
                printf("%s\n", history_string1);
                classify2(history_string1, info3);
                nol_in_input_list--;
                classify2(history_string2, info8);
            }
            fclose(fgptr);
            FILE *fh_ptr;
            char file_address2[100];
            int edit_line;
            printf("Which Deal line Do You Want To Edit? ");
            scanf("%d", &edit_line);
            printf("Please Enter Your File Address: ");
            scanf("%s", file_address2);
            fh_ptr = fopen(file_address2, "r");
            if (fh_ptr==NULL)
                while (1) {
                    printf("THE REQUIRED FILE NOT FOUND.\n");
                    printf("Please Enter Your File Address Again: ");
                    scanf("%s",file_address2);
                    fh_ptr=fopen(file_address2,"r");
                    if(fh_ptr!=NULL)
                        break;
                }
            printf("Please Enter Your Arbitrary Label:");
            scanf("%s", info3[edit_line - 1].label);
            fh_ptr = fopen(file_address2, "a");
            fprintf(fh_ptr, "%s,%s,%s,%s,%s,%s,%s\n",
                    info3[edit_line - 1].buying,
                    info3[edit_line - 1].maint,
                    info3[edit_line - 1].doors,
                    info3[edit_line - 1].persons,
                    info3[edit_line - 1].lug_boot,
                    info3[edit_line - 1].safety,
                    info3[edit_line - 1].label);
            for (int g = 0; g < nol_in_input_list; g++) {
                fprintf(fe_ptr, "%s,%s,%s,%s,%s,%s,%s\n",
                        info3[g].buying,
                        info3[g].maint,
                        info3[g].doors,
                        info3[g].persons,
                        info3[g].lug_boot,
                        info3[g].safety,
                        info3[g].label);
            }
            fclose(fh_ptr);
            fclose(fe_ptr);
        } else if (requested_feature == 4) {
            feature4();
        } else if (requested_feature == 5) {
            printf("Hope To Meet You Again. Have A Good Time :)\n");
            return 0;
        }
    }while(requested_feature!=5);
}
void classify1(char line_of_text[],info info1[] ){
    info info2;
    char* token;
    token=strtok(line_of_text,",");
    strcpy(info2.buying,token);
    token=strtok(NULL,",");
    strcpy(info2.maint,token);
    token=strtok(NULL,",");
    strcpy(info2.doors,token);
    token=strtok(NULL,",");
    strcpy(info2.persons,token);
    token=strtok(NULL,",");
    strcpy(info2.lug_boot,token);
    token=strtok(NULL,",");
    strcpy(info2.safety,token);
    token=strtok(NULL,",");
    strcpy(info2.label,token);
    info1[i]=info2;
    i++;
}
void classify2(char line_of_text[],info info1[] ){
    info info2;
    char* token;
    token=strtok(line_of_text,",");
    strcpy(info2.buying,token);
    token=strtok(NULL,",");
    strcpy(info2.maint,token);
    token=strtok(NULL,",");
    strcpy(info2.doors,token);
    token=strtok(NULL,",");
    strcpy(info2.persons,token);
    token=strtok(NULL,",");
    strcpy(info2.lug_boot,token);
    token=strtok(NULL,",");
    strcpy(info2.safety,token);
    token=strtok(NULL,",");
    strcpy(info2.label,token);
    info1[nol_in_input_list]=info2;
    nol_in_input_list++;
}
int sort_by_result_vgood(info info1[],int y){
    int k=0;
    info temp;
    for (int i1=0;i1<y;i1++){
        for (int i2=i1;i2<y;i2++){
            if(strcmp(info1[i2].label,"vgood")==0){
                temp=info1[i1];
                info1[i1]=info1[i2];
                info1[i2]=temp;
                k++;
                break;
            }
        }
    }
    return k;
}
int sort_by_result_good(info info1[],int y,int l) {
    int k = 0;
    l=k1;
    info temp;
    for (int i1 = l; i1 < y;i1++) {
        for (int i2 = i1; i2 < y; i2++) {
//            printf("\n%d\n",i2);
            if (strcmp(info1[i2].label, "good") == 0) {
                temp = info1[i1];
                info1[i1] = info1[i2];
                info1[i2] = temp;
                k++;
                break;
            }
        }
    }
    return k;
}
int sort_by_result_acc(info info1[],int y,int l,int r) {
    l=k1;
    r=k2;
    int k = 0;
    info temp;
    for (int i1 = l+r; i1 < y; i1++) {
        for (int i2 = i1; i2 < y; i2++) {
            if (strcmp(info1[i2].label, "acc") == 0) {
                temp = info1[i1];
                info1[i1] = info1[i2];
                info1[i2] = temp;
                k++;
                break;
            }
        }
    }
    return k;
}
void matching_input_string(char input_string[],info info1[]){
    first_number_of_vgood(info1);
    second_number_of_vgood(info1);
    third_number_of_vgood(info1);
    fourth_number_of_vgood(info1);
    fifth_number_of_vgood(info1);
    sixth_number_of_vgood(info1);
    first_number_of_good(info1);
    second_number_of_good(info1);
    third_number_of_good(info1);
    fourth_number_of_good(info1);
    fifth_number_of_good(info1);
    sixth_number_of_good(info1);
    first_number_of_acc(info1);
    second_number_of_acc(info1);
    third_number_of_acc(info1);
    fourth_number_of_acc(info1);
    fifth_number_of_acc(info1);
    sixth_number_of_acc(info1);
    info info2;
    char *token;
    token = strtok(input_string, ",");
    strcpy(info2.buying, token);
    token = strtok(NULL, ",");
    strcpy(info2.maint, token);
    token = strtok(NULL, ",");
    strcpy(info2.doors, token);
    token = strtok(NULL, ",");
    strcpy(info2.persons, token);
    token = strtok(NULL, ",");
    strcpy(info2.lug_boot, token);
    token = strtok(NULL, ",");
    strcpy(info2.safety, token);
    //    calculating the probability of vgood
    final_number1 = (float) k1 / i;
//        printf("%f\n",final_number1);
    if (strcmp(info2.buying, "vhigh") == 0) {
        final_number1 *= (float) vgood_buying_vhigh / k1;
//            printf("\n%d,%f\n",vgood_buying_vhigh,final_number1);
    }
    else if (strcmp(info2.buying, "high") == 0) {
        final_number1 *= (float) vgood_buying_high / k1;
    }
    else if (strcmp(info2.buying, "med") == 0) {
        final_number1 *= (float) vgood_buying_med / k1;
    }
    else if (strcmp(info2.buying, "low") == 0) {
        final_number1 *= (float) vgood_buying_low / k1;
    }
    if (strcmp(info2.maint, "vhigh") == 0) {
        final_number1 *= (float) vgood_maint_vhigh / k1;
    }
    else if (strcmp(info2.maint, "high") == 0) {
        final_number1 *= (float) vgood_maint_high / k1;
    }
    else if (strcmp(info2.maint, "med") == 0) {
        final_number1 *= (float) vgood_maint_med / k1;
    }
    else if (strcmp(info2.maint, "low") == 0) {
        final_number1 *= (float) vgood_maint_low / k1;
//            printf("\n%d,%f\n",vgood_maint_low,final_number1);
    }
    if (strcmp(info2.doors, "2") == 0) {
        final_number1 *= (float) vgood_doors_2 / k1;
//            printf("\n%d,%f\n",vgood_doors_2,final_number1);
    }
    else if (strcmp(info2.doors, "3") == 0) {
        final_number1 *= (float) vgood_doors_3 / k1;
    }
    else if (strcmp(info2.doors, "4") == 0) {
        final_number1 *= (float) vgood_doors_4 / k1;
    }
    else if (strcmp(info2.doors, "more") == 0) {
        final_number1 *= (float) vgood_doors_more / k1;
    }
    if (strcmp(info2.persons, "2") == 0) {
        final_number1 *= (float) vgood_persons_2 / k1;
//            printf("\n%d,%f\n",vgood_persons_2,final_number1);
    }
    else if (strcmp(info2.persons, "4") == 0) {
        final_number1 *= (float) vgood_persons_4 / k1;
    }
    else if (strcmp(info2.persons, "more") == 0) {
        final_number1 *= (float) vgood_persons_more / k1;
    }
    if (strcmp(info2.lug_boot, "small") == 0) {
        final_number1 *= (float) vgood_lug_boot_small / k1;
    }
    else if (strcmp(info2.lug_boot, "med") == 0) {
        final_number1 *= (float) vgood_lug_boot_med / k1;
    }
    else if (strcmp(info2.lug_boot, "big") == 0) {
        final_number1 *= (float) vgood_lug_boot_big / k1;
//            printf("\n%d,%f\n",vgood_lug_boot_big,final_number1);
    }
    if (strcmp(info2.safety, "high") == 0) {
        final_number1 *= (float) vgood_safety_high / k1;
//            printf("\nkk%d,%f\n",vgood_safety_high,final_number1);
    }
    else if (strcmp(info2.safety, "med") == 0) {
        final_number1 *= (float) vgood_safety_med / k1;
    }
    else if (strcmp(info2.safety, "low") == 0) {
        final_number1 *= (float) vgood_safety_low / k1;
    }

    //    calculating the probability of good
    final_number2 = (float) k2 / i;
    if (strcmp(info2.buying, "vhigh") == 0) {
        final_number2 *= (float) good_buying_vhigh / k2;
    }
    else if (strcmp(info2.buying, "high") == 0) {
        final_number2 *= (float) good_buying_high / k2;
    }
    else if (strcmp(info2.buying, "med") == 0) {
        final_number2 *= (float) good_buying_med / k2;
    }
    else if (strcmp(info2.buying, "low") == 0) {
        final_number2 *= (float) good_buying_low / k2;
    }
    if (strcmp(info2.maint, "vhigh") == 0) {
        final_number2 *= (float) good_maint_vhigh / k2;
    } else if (strcmp(info2.maint, "high") == 0) {
        final_number2 *= (float) good_maint_high / k2;
    } else if (strcmp(info2.maint, "med") == 0) {
        final_number2 *= (float) good_maint_med / k2;
    } else if (strcmp(info2.maint, "low") == 0) {
        final_number2 *= (float) good_maint_low / k2;
    }
    if (strcmp(info2.doors, "2") == 0) {
        final_number2 *= (float) good_doors_2 / k2;
    }
    else if (strcmp(info2.doors, "3") == 0) {
        final_number2 *= (float) good_doors_3 / k2;
    }
    else if (strcmp(info2.doors, "4") == 0) {
        final_number2 *= (float) good_doors_4 / k2;
    } else if (strcmp(info2.doors, "more") == 0) {
        final_number2 *= (float) good_doors_more / k2;
    }
    if (strcmp(info2.persons, "2") == 0) {
        final_number2 *= (float) good_persons_2 / k2;
    } else if (strcmp(info2.persons, "4") == 0) {
        final_number2 *= (float) good_persons_4 / k2;
    } else if (strcmp(info2.persons, "more") == 0) {
        final_number2 *= (float) good_persons_more / k2;
    }
    if (strcmp(info2.lug_boot, "small") == 0) {
        final_number2 *= (float) good_lug_boot_small / k2;
    } else if (strcmp(info2.lug_boot, "med") == 0) {
        final_number2 *= (float) good_lug_boot_med / k2;
    } else if (strcmp(info2.lug_boot, "big") == 0) {
        final_number2 *= (float) good_lug_boot_big / k2;
    }
    if (strcmp(info2.safety, "high") == 0) {
        final_number2 *= (float) good_safety_high / k2;
    } else if (strcmp(info2.safety, "med") == 0) {
        final_number2 *= (float) good_safety_med / k2;
    } else if (strcmp(info2.safety, "low") == 0) {
        final_number2 *= (float) good_safety_low / k2;
    }
    //    calculating the probability of acc
    final_number3 = (float) k3 / i;
    if (strcmp(info2.buying, "vhigh") == 0) {
        final_number3 *= (float) acc_buying_vhigh / k3;
    } else if (strcmp(info2.buying, "high") == 0) {
        final_number3 *= (float) acc_buying_high / k3;
    } else if (strcmp(info2.buying, "med") == 0) {
        final_number3 *= (float) acc_buying_med / k3;
    } else if (strcmp(info2.buying, "low") == 0) {
        final_number3 *= (float) acc_buying_low / k3;
    }
    if (strcmp(info2.maint, "vhigh") == 0) {
        final_number3 *= (float) acc_maint_vhigh / k3;
    } else if (strcmp(info2.maint, "high") == 0) {
        final_number3 *= (float) acc_maint_high / k3;
    } else if (strcmp(info2.maint, "med") == 0) {
        final_number3 *= (float) acc_maint_med / k3;
    } else if (strcmp(info2.maint, "low") == 0) {
        final_number3 *= (float) acc_maint_low / k3;
    }
    if (strcmp(info2.doors, "2") == 0) {
        final_number3 *= (float) acc_doors_2 / k3;
    } else if (strcmp(info2.doors, "3") == 0) {
        final_number3 *= (float) acc_doors_3 / k3;
    } else if (strcmp(info2.doors, "4") == 0) {
        final_number3 *= (float) acc_doors_4 / k3;
    } else if (strcmp(info2.doors, "more") == 0) {
        final_number3 *= (float) acc_doors_more / k3;
    }
    if (strcmp(info2.persons, "2") == 0) {
        final_number3 *= (float) acc_persons_2 / k3;
    } else if (strcmp(info2.persons, "4") == 0) {
        final_number3 *= (float) acc_persons_4 / k3;
    } else if (strcmp(info2.persons, "more") == 0) {
        final_number3 *= (float) acc_persons_more / k3;
    }
    if (strcmp(info2.lug_boot, "small") == 0) {
        final_number3 *= (float) acc_lug_boot_small / k3;
    } else if (strcmp(info2.lug_boot, "med") == 0) {
        final_number3 *= (float) acc_lug_boot_med / k3;
    } else if (strcmp(info2.lug_boot, "big") == 0) {
        final_number3 *= (float) acc_lug_boot_big / k3;
    }
    if (strcmp(info2.safety, "high") == 0) {
        final_number3 *= (float) acc_safety_high / k3;
    } else if (strcmp(info2.safety, "med") == 0) {
        final_number3 *= (float) acc_safety_med / k3;
    } else if (strcmp(info2.safety, "low") == 0) {
        final_number3 *= (float) acc_safety_low / k3;
    }
}
void first_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].buying, "vhigh") == 0) {
            vgood_buying_vhigh++;
//                printf("\n0%d\n",vgood_buying_vhigh);
        }
        else if (strcmp(info1[i2].buying, "high") == 0)
            vgood_buying_high++;
        else if (strcmp(info1[i2].buying, "med") == 0)
            vgood_buying_med++;
        else if (strcmp(info1[i2].buying, "low") == 0)
            vgood_buying_low++;
    }
}
void second_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].maint, "vhigh") == 0)
            vgood_maint_vhigh++;
        else if (strcmp(info1[i2].maint, "high") == 0)
            vgood_maint_high++;
        else if (strcmp(info1[i2].maint, "med") == 0)
            vgood_maint_med++;
        else if (strcmp(info1[i2].maint, "low") == 0)
            vgood_maint_low++;
    }
}
void third_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].doors, "2") == 0)
            vgood_doors_2++;
        else if (strcmp(info1[i2].doors, "3") == 0)
            vgood_doors_3++;
        else if (strcmp(info1[i2].doors, "4") == 0)
            vgood_doors_4++;
        else if (strcmp(info1[i2].doors, "more") == 0)
            vgood_doors_more++;
    }
}
void fourth_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].persons, "2") == 0)
            vgood_persons_2++;
        else if (strcmp(info1[i2].persons, "4") == 0)
            vgood_persons_4++;
        else if (strcmp(info1[i2].persons, "more") == 0)
            vgood_persons_more++;
    }
}
void fifth_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].lug_boot, "small") == 0)
            vgood_lug_boot_small++;
        else if (strcmp(info1[i2].lug_boot, "med") == 0)
            vgood_lug_boot_med++;
        else if (strcmp(info1[i2].lug_boot, "big") == 0) {
            vgood_lug_boot_big++;
//                printf("ii");
        }
    }
}
void sixth_number_of_vgood(info info1[]) {
    for (int i2 = 0; i2 < k1; i2++) {
        if (strcmp(info1[i2].safety, "low") == 0)
            vgood_safety_low++;
        else if (strcmp(info1[i2].safety, "med") == 0)
            vgood_safety_med++;
        else if (strcmp(info1[i2].safety, "high") == 0)
            vgood_safety_high++;
    }
}
void first_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].buying, "vhigh") == 0)
            good_buying_vhigh++;
        else if (strcmp(info1[i2].buying, "high") == 0)
            good_buying_high++;
        else if (strcmp(info1[i2].buying, "med") == 0)
            good_buying_med++;
        else if (strcmp(info1[i2].buying, "low") == 0)
            good_buying_low++;
    }
}
void second_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].maint, "vhigh") == 0)
            good_maint_vhigh++;
        else if (strcmp(info1[i2].maint, "high") == 0)
            good_maint_high++;
        else if (strcmp(info1[i2].maint, "med") == 0)
            good_maint_med++;
        else if (strcmp(info1[i2].maint, "low") == 0)
            good_maint_low++;
    }
}
void third_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].doors, "2") == 0)
            good_doors_2++;
        else if (strcmp(info1[i2].doors, "3") == 0)
            good_doors_3++;
        else if (strcmp(info1[i2].doors, "4") == 0)
            good_doors_4++;
        else if (strcmp(info1[i2].doors, "more") == 0)
            good_doors_more++;
    }
}
void fourth_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].persons, "2") == 0)
            good_persons_2++;
        else if (strcmp(info1[i2].persons, "4") == 0)
            good_persons_4++;
        else if (strcmp(info1[i2].persons, "more") == 0)
            good_persons_more++;
    }
}
void fifth_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].lug_boot, "small") == 0)
            good_lug_boot_small++;
        else if (strcmp(info1[i2].lug_boot, "med") == 0)
            good_lug_boot_med++;
        else if (strcmp(info1[i2].lug_boot, "big") == 0)
            good_lug_boot_big++;
    }
}
void sixth_number_of_good(info info1[]) {
    for (int i2 = k1; i2 < k1 + k2; i2++) {
        if (strcmp(info1[i2].safety, "low") == 0)
            good_safety_low++;
        else if (strcmp(info1[i2].safety, "med") == 0)
            good_safety_med++;
        else if (strcmp(info1[i2].safety, "high") == 0)
            good_safety_high++;
    }
}
void first_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].buying, "vhigh") == 0)
            acc_buying_vhigh++;
        else if (strcmp(info1[i2].buying, "high") == 0)
            acc_buying_high++;
        else if (strcmp(info1[i2].buying, "med") == 0)
            acc_buying_med++;
        else if (strcmp(info1[i2].buying, "low") == 0)
            acc_buying_low++;
    }
}
void second_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].maint, "vhigh") == 0)
            acc_maint_vhigh++;
        else if (strcmp(info1[i2].maint, "high") == 0)
            acc_maint_high++;
        else if (strcmp(info1[i2].maint, "med") == 0)
            acc_maint_med++;
        else if (strcmp(info1[i2].maint, "low") == 0)
            acc_maint_low++;
    }
}
void third_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].doors, "2") == 0)
            acc_doors_2++;
        else if (strcmp(info1[i2].doors, "3") == 0)
            acc_doors_3++;
        else if (strcmp(info1[i2].doors, "4") == 0)
            acc_doors_4++;
        else if (strcmp(info1[i2].doors, "more") == 0)
            acc_doors_more++;
    }
}
void fourth_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].persons, "2") == 0)
            acc_persons_2++;
        else if (strcmp(info1[i2].persons, "4") == 0)
            acc_persons_4++;
        else if (strcmp(info1[i2].persons, "more") == 0)
            acc_persons_more++;
    }
}
void fifth_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].lug_boot, "small") == 0)
            acc_lug_boot_small++;
        else if (strcmp(info1[i2].lug_boot, "med") == 0)
            acc_lug_boot_med++;
        else if (strcmp(info1[i2].lug_boot, "big") == 0)
            acc_lug_boot_big++;
    }
}
void sixth_number_of_acc(info info1[]) {
    for (int i2 = k1 + k2; i2 < k1 + k2 + k3; i2++) {
        if (strcmp(info1[i2].safety, "low") == 0)
            acc_safety_low++;
        else if (strcmp(info1[i2].safety, "med") == 0)
            acc_safety_med++;
        else if (strcmp(info1[i2].safety, "high") == 0)
            acc_safety_high++;
    }
}
void feature_1(){
    char line_of_text[100];
    char file_address[100];
    printf("Please Enter Your File Address: ");
    scanf("%s",file_address);
    final_number1=1;
    final_number2=1;
    final_number3=1;
    FILE* file_ptr;
    file_ptr=fopen(file_address,"r");
    if (file_ptr==NULL)
        while (1) {
            printf("THE REQUIRED FILE NOT FOUND.\n");
            printf("Please Enter Your File Address Again: ");
            scanf("%s",file_address);
            file_ptr=fopen(file_address,"r");
            if(file_ptr!=NULL)
                break;
        }
    while(!feof(file_ptr)){
        fscanf(file_ptr,"%s\n",line_of_text);
        classify1(line_of_text,info1);
    }
    k1= sort_by_result_vgood(info1,i);
    k2= sort_by_result_good(info1,i,k1);
    k3= sort_by_result_acc(info1,i,k1,k2);
    k4=i-k1-k2-k3;
    printf("Please Enter Your Input String: ");
    scanf("%s",input_string);
    char input_string2[100];
    strcpy(input_string2,input_string);
    check(input_string2);
    FILE* file_ptr1;
    file_ptr1= fopen("input_list.txt","a");
    fprintf(file_ptr1,"%s,",input_string);
    matching_input_string(input_string,info1);
    final_number4=1-final_number1-final_number2-final_number3;
    int final=comparison();
    if (final==1)
        fprintf(file_ptr1,"vgood\n");
    else if(final==2)
        fprintf(file_ptr1,"good\n");
    else if(final==3)
        fprintf(file_ptr1,"acc\n");
    else if(final==4)
        fprintf(file_ptr1,"unacc\n");
    final_result_feature_1(final);
    fclose(file_ptr1);
    fclose(file_ptr);
}
int comparison(){
    if (final_number1>final_number2&&final_number1>final_number3&&final_number1>final_number4)
        return 1;
    else if(final_number2>final_number1&&final_number2>final_number3&&final_number2>final_number4)
        return 2;
    else if(final_number3>final_number1&&final_number3>final_number2&&final_number3>final_number4)
        return 3;
    else
        return 4;
}
void main_list1(){
    printf("Welcome\n");
    printf("1. Predict new Trade\n");
    printf("2. Trade Prediction History\n");
    printf("3. Label new Trades\n");
    printf("4. Prediction Evaluation\n");
    printf("5. Exit\n");
}void main_list2(){
    printf("1. Predict new Trade\n");
    printf("2. Trade Prediction History\n");
    printf("3. Label new Trades\n");
    printf("4. Prediction Evaluation\n");
    printf("5. Exit\n");
}
void final_result_feature_1(int final){
    if (final==1)
        printf("THE MOST PROBABLE GUESS IS VGOOD LABEL\n");
    else if(final==2)
        printf("THE MOST PROBABLE GUESS IS GOOD LABEL\n");
    else if(final==3)
        printf("THE MOST PROBABLE GUESS IS ACC LABEL\n");
    else
        printf("THE MOST PROBABLE GUESS IS UNACC LABEL\n");
}
void feature4() {
    nol_in_input_list=0;
    FILE* ft_ptr;
    ft_ptr= fopen("input_list.txt","r");
    FILE* fe_ptr;
    fe_ptr= fopen("edited_list.txt","r");
    while(!feof(ft_ptr)){
        char history_string1[100];
        char history_string2[100];
        fscanf(ft_ptr,"%s\n",history_string1);
        fscanf(fe_ptr,"%s\n",history_string2);
        classify2(history_string1,info3);
        nol_in_input_list--;
        classify2(history_string2,info8);
    }
    evaluation_vgood();
    evaluation_good();
    evaluation_acc();
    evaluation_unacc();
    printf("THE REQUIRED STATISTICS FOR VGOOD LABEL IS:\n");
    float precision_vgood=(float)(tp_vgood)/(tp_vgood+fp_vgood);
    float recall_vgood=(float)(tp_vgood)/(tp_vgood+fn_vgood);
    float f1score_vgood=(float)2*(tp_vgood)/(2*tp_vgood+fn_vgood+fp_vgood);
    printf("\tPRECISION=%f\tRECALL=%f\n\t\tF1SCORE=%f\n",precision_vgood,recall_vgood,f1score_vgood);
    printf("THE REQUIRED STATISTICS FOR GOOD LABEL IS:\n");
    float precision_good=(float)(tp_good)/(tp_good+fp_good);
    float recall_good=(float)(tp_good)/(tp_good+fn_good);
    float f1score_good=(float)2*(tp_good)/(2*tp_good+fn_good+fp_good);
    printf("\tPRECISION=%f\tRECALL=%f\n\t\tF1SCORE=%f\n",precision_good,recall_good,f1score_good);
    printf("THE REQUIRED STATISTICS FOR ACC LABEL IS:\n");
    float precision_acc=(float)(tp_acc)/(tp_acc+fp_acc);
    float recall_acc=(float)(tp_acc)/(tp_acc+fn_acc);
    float f1score_acc=(float)2*(tp_acc)/(2*tp_acc+fn_acc+fp_acc);
    printf("\tPRECISION=%f\tRECALL=%f\n\t\tF1SCORE=%f\n",precision_acc,recall_acc,f1score_acc);
    printf("THE REQUIRED STATISTICS FOR UNACC LABEL IS:\n");
    float precision_unacc=(float)(tp_unacc)/(tp_unacc+fp_unacc);
    float recall_unacc=(float)(tp_unacc)/(tp_unacc+fn_unacc);
    float f1score_unacc=(float)2*(tp_unacc)/(2*tp_unacc+fn_unacc+fp_unacc);
    printf("\tPRECISION=%f\tRECALL=%f\n\t\tF1SCORE=%f\n",precision_unacc,recall_unacc,f1score_unacc);
}
void evaluation_vgood(){
    for (int t=0;t<nol_in_input_list;t++){
        if (strcmp(info8[t].label,info3[t].label)==0&&
            strcmp(info8[t].label,"vgood")==0){
            tp_vgood++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"vgood")!=0&&
            strcmp(info3[t].label,"vgood")!=0){
            tn_vgood++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info3[t].label,"vgood")!=0&&
            strcmp(info8[t].label,"vgood")==0){
            fn_vgood++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"vgood")!=0&&
            strcmp(info3[t].label,"vgood")==0){
            fp_vgood++;
        }
    }
}void evaluation_good(){
    for (int t=0;t<nol_in_input_list;t++){
        if (strcmp(info8[t].label,info3[t].label)==0&&
            strcmp(info8[t].label,"good")==0){
            tp_good++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"good")!=0&&
            strcmp(info3[t].label,"good")!=0){
            tn_good++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info3[t].label,"good")!=0&&
            strcmp(info8[t].label,"good")==0){
            fn_good++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"good")!=0&&
            strcmp(info3[t].label,"good")==0){
            fp_good++;
        }
    }
}void evaluation_acc(){
    for (int t=0;t<nol_in_input_list;t++){
        if (strcmp(info8[t].label,info3[t].label)==0&&strcmp(info8[t].label,"acc")==0){
            tp_acc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"acc")!=0&&
            strcmp(info3[t].label,"acc")!=0){
            tn_acc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info3[t].label,"acc")!=0&&
            strcmp(info8[t].label,"acc")==0){
            fn_acc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"acc")!=0&&
            strcmp(info3[t].label,"acc")==0){
            fp_acc++;
        }
    }
}void evaluation_unacc(){
    for (int t=0;t<nol_in_input_list;t++){
        if (strcmp(info8[t].label,info3[t].label)==0&&
            strcmp(info8[t].label,"unacc")==0){
            tp_unacc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"unacc")!=0&&
            strcmp(info3[t].label,"unacc")!=0){
            tn_unacc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info3[t].label,"unacc")!=0&&
            strcmp(info8[t].label,"unacc")==0){
            fn_unacc++;
        }
        if (strcmp(info8[t].label,info3[t].label)!=0&&
            strcmp(info8[t].label,"unacc")!=0&&
            strcmp(info3[t].label,"unacc")==0){
            fp_unacc++;
        }
    }
}
void check(char line_of_text[]){
    int q=0;
    do {
        if(q!=0){
            printf("PLEASE ENTER YOUR STRING AGAIN.\n");
            scanf("%s",line_of_text);
            q=0;
        }
        char *token;
        token = strtok(line_of_text, ",");
        if (strcmp(token, "vhigh") != 0 &&
            strcmp(token, "high") != 0 &&
            strcmp(token, "med") != 0 &&
            strcmp(token, "low") != 0) {
            printf("THE INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
        token = strtok(NULL, ",");
        if (strcmp(token, "vhigh") != 0 &&
            strcmp(token, "high") != 0 &&
            strcmp(token, "med") != 0 &&
            strcmp(token, "low") != 0) {
            printf("INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
        token = strtok(NULL, ",");
        if (strcmp(token, "2") != 0 &&
            strcmp(token, "3") != 0 &&
            strcmp(token, "4") != 0 &&
            strcmp(token, "more") != 0) {
            printf("INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
        token = strtok(NULL, ",");
        if (strcmp(token, "2") != 0 &&
            strcmp(token, "4") != 0 &&
            strcmp(token, "more") != 0) {
            printf("INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
        token = strtok(NULL, ",");
        if (strcmp(token, "small") != 0 &&
            strcmp(token, "med") != 0 &&
            strcmp(token, "big") != 0) {
            printf("INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
        token = strtok(NULL, ",");
        if (strcmp(token, "low") != 0 &&
            strcmp(token, "med") != 0 &&
            strcmp(token, "high") != 0) {
            printf("INPUT STRING IS NOT VALID.\n");
            q++;
            continue;
        }
    }while (q!=0);
}
