#include <stdio.h>

struct UserAccount {
    int id;
    int plan;
    long fee;
    int days;
    int devices;
};

int main() {
    struct UserAccount users[100];
    int n, i, j;
    long pre_mrr = 0, post_mrr = 0;

    printf("Nhap so luong tai khoan N (1-100): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nhap ID, Plan(0-2), Fee, Days, Devices cho TK %d: ", i + 1);
        scanf("%d %d %ld %d %d", &users[i].id, &users[i].plan, &users[i].fee, &users[i].days, &users[i].devices);
        pre_mrr += users[i].fee; 
    }

    for (i = 0; i < n; i++) {
        if (users[i].devices <= 0) users[i].devices = 1;
        if (users[i].days <= 0) users[i].plan = 0;

        int max_dev = 1;
        if (users[i].plan == 1) { 
            users[i].fee = 120000; 
            max_dev = 2; 
        } else if (users[i].plan == 2) { 
            users[i].fee = 300000; 
            max_dev = 5; 
        } else { 
            users[i].plan = 0; 
            users[i].fee = 0; 
            max_dev = 1; 
        }

        if (users[i].devices > max_dev) {
            users[i].devices = max_dev;
        }

        post_mrr += users[i].fee; 
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            int swap = 0;
            
            if (users[j].plan == 0 && users[j+1].plan > 0) {
                swap = 1;
            } 
            else if (users[j].plan > 0 && users[j+1].plan > 0 && users[j].fee < users[j+1].fee) {
                swap = 1;
            }

            if (swap == 1) {
                struct UserAccount temp = users[j];
                users[j] = users[j+1];
                users[j+1] = temp;
            }
        }
    }

    printf("\n--- BAO CAO SAU KIEM TOAN ---\n");
    printf("ID\tPlan\tFee\tDays\tDevices\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%ld\t%d\t%d\n", users[i].id, users[i].plan, users[i].fee, users[i].days, users[i].devices);
    }
    printf("\nMRR Truoc kiem toan: %ld VND\n", pre_mrr);
    printf("MRR Sau kiem toan  : %ld VND\n", post_mrr);

    return 0;
}