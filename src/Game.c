#include <stdio.h>
#include <ctype.h>
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "Colors.h"

void startBattle() {
    Player* player = createPlayer();
    Enemy* enemy = createEnemy();

    while(player->hp > 0 && enemy->hp > 0) {
        turn(player, enemy);
    }

    if(player->hp < 0) {
        SetConsoleColor(LIGHT_RED_COLOR);
        printf("The enemy has won...\n");
        SetConsoleColor(RESET_COLOR);
    } else {
        SetConsoleColor(LIGHT_CYAN_COLOR);
        printf("%s has won!\n", player->playerName);
        SetConsoleColor(RESET_COLOR);
    }

    getch();

    destroyEnemy(enemy);
    destroyPlayer(player);
}

int main(int argc, char* argv[]) {
    system("cls");
    
    char opt;

    for(;;) {
        SetConsoleColor(CYAN_COLOR);

        printf("> Start battle (s/n)? ");
        scanf("%c", &opt);

        SetConsoleColor(RESET_COLOR);

        if(tolower(opt) == 'n') exit(0);

        system("cls");
        startBattle();
    }

    return 0;
}