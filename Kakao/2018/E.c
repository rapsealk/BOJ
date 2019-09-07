#include <stdio.h>

//int song[100001];
int numberOfSongOfSinger[100001];
//int singerOf[100001];
//int parentOf[100001];
int accScoreOfSinger[100001];
//int duplicatedSingerOnSubtree[100001];
//int numberOfNodeOnSubtree[100001];
int overtimeOfSong[100001];

typedef struct {
    int singer;
    int parent;
    int duplicatedSingerOnSubtree;
    int numberOfNodeOnSubtree;
    node_t* next, left_child, right_child;
} node_t;

node_t song[100001];

int main() {
    int N, K, J, i, node;
    int T, P, S, weight;
    // int queue[100000], qhead, qtail;
    node_t* queue[100000];
    int qhead, qtail;
    node_t* nodeptr = NULL, temp = NULL;
    scanf("%d%d%d", &N, &K, &J);
    for (i = 1; i <= 100000; i++) overtimeOfSong[i] = -1;
    for (i = 2; i <= N; i++) {
        scanf("%d", &song[i].parent);
        if (song[song[i].parent].left_child == NULL) {
            song[song[i].parent].left_child = song[song[i].parent].right_child = &song[i];
        } else {
            song[song[i].parent].right_child->next = &song[i];
            song[song[i].parent].right_child = &song[i];
        }
        node = i;
        while (song[node].parent) {
            song[song[node].parent].numberOfNodeOnSubtree += song[node].numberOfNodeOnSubtree + 1;
            node = song[node].parent;
        }
        /*
        scanf("%d", &parentOf[i]);
        node = i;
        while (parentOf[node]) {
            numberOfNodeOnSubtree[parentOf[node]] += numberOfNodeOnSubtree[node] + 1;
            node = parentOf[node];
        }
        */
    }
    for (i = 1; i <= N; i++) {
        scanf("%d", &song[i].singer);
        numberOfSongOfSinger[song[i].singer] += 1;
        node = i;
        while (node) {
            if (song[node].singer == song[song[node].parent].singer)
                song[song[node].parent].duplicatedSingerOnSubtree = song[node].duplicatedSingerOnSubtree + 1;
            node = song[node].parent;
        }
        /*
        scanf("%d", &singerOf[i]);
        numberOfSongOfSinger[singerOf[i]] += 1;
        node = i;
        while (node) {
            if (singerOf[node] == singerOf[parentOf[node]])
                duplicatedSingerOnSubtree[parentOf[node]] = duplicatedSingerOnSubtree[node] + 1;
            node = parentOf[node];
        }
        */
    }
    while (K--) {
        scanf("%d%d%d", &T, &P, &S);
        weight = S / (song[P].numberOfNodeOnSubtree + 1);
        qhead = qtail = 0;
        queue[qtail++] = &P;
        while (qhead < qtail) {
            nodeptr = queue[qhead++];
            if (song[node].left_child != NULL) {
                for (temp = nodeptr->left_child; temp != NULL; nodeptr = tepm->next) {
                    queue[qhead++] = temp;
                }
                accScoreOfSinger[nodetpr->singer] += weight;
                if (overtimeOfSong[nodeptr->singer] == -1 && (double) accScoreOfSinger[singerOf[nodeptr->singer]] / numberOfSongOfSinger[nodeptr->singer] > J) {
                    overtimeOfSong[nodeptr->singer] = T;
                }
            }
        }
        /*
        scanf("%d%d%d", &T, &P, &S);
        weight = S / (numberOfNodeOnSubtree[P]+1);
        // printf("weight: %d\n", weight);
        qhead = qtail = 0;
        queue[qtail++] = P;
        // TODO bottleneck
        while (qhead < qtail) {
            node = queue[qhead++];
            for (i = 1; i <= N; i++) if (parentOf[i] == node) {
                queue[qtail++] = i;
                // printf("song(%d) is children of song(%d)\n", i, node);
            }
            accScoreOfSinger[singerOf[node]] += weight;
            // printf("add weight(%d) to singer(%d)\n", weight, singerOf[node]);
            if (overtimeOfSong[singerOf[node]] == -1 && (double) accScoreOfSinger[singerOf[node]] / numberOfSongOfSinger[singerOf[node]] > J) {
                overtimeOfSong[singerOf[node]] = T;
                // printf("singer(%d) achieved at T(%d)\n", singerOf[node], T);
            }
        }
        */
    }
    for (i = 1; i <= N; i++) printf("%d\n", overtimeOfSong[singerOf[i]]);
    return 0;
}