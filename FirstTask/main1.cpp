// Задание 1. Банкетный стол
// Что нужно сделать
// По поводу успешного прохождения двумерных массивов собирается банкет, организуется стол на 12 персон. 
// Есть два VIP-места, они рядом во главе стола. 
// Стол протяжён в длину, места расположены в два ряда. 
// Каждый пришедший должен быть «упакован» соответствующим образом. 
// Во-первых, столовые приборы: по три на каждого человека (вилка, ложка, нож) и одна маленькая дополнительная ложечка для VIP-персон (для десерта). 
// Во-вторых, тарелки: каждому по две (для первого и второго блюда) и ещё одна тарелка для VIP-персон (для десерта). 
// В-третьих, стулья: минимум один для каждого гостя. 
// Заведите соответствующие двумерные массивы для количества приборов, посуды и стульев и проинициализируйте их.

// Но это ещё не всё. 
// На банкете после инициализации происходят некоторые события. 
// Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому на данное место был приставлен ещё один стул. 
// С третьего места во втором ряду в неизвестном направлении была украдена ложка. 
// Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки, и стала есть суп десертной. 
// За ненадобностью официант забрал у VIP-гостя одну десертную тарелку, ведь есть десерт ложкой, которая уже побывала уже в супе, неприлично. 
// Больше без происшествий, однако эти события на банкете надо отразить в инициализированных ранее массивах.

#include <iostream>

int main() {
    int tableware[2][6] = {{4, 3, 3, 3, 3, 3},
                           {4, 3, 3, 3, 3, 3}};
    int dishes[2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};
    
    chairs[1][5] += 1; /*Добавлен стул для ребёнка*/
    tableware[2][3] -= 1; /*Украдена ложка*/
    tableware[2][1] -= 1; /*VIP ложку отдал*/
    tableware[2][3] += 1; /*Гость ложку взял*/
    dishes[2][1] -= 1; /*У VIPа забрали тарелку*/

}