#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

bool isAgedBrie(string name)
{
    if (name == "Aged Brie")
        return true;

    return false;
}

bool isSulfuras(string name)
{
    if (name == "Sulfuras, Hand of Ragnaros")
        return true;
    return false;
}

bool isConjured(string name)
{
    if (name == "Conjured Mana Cake")
        return true;
    return false;
}

void updateGeneral(Item &item)
{

    if (item.sellIn < 0 && item.quality >= 2) {
        item.quality = item.quality - 2;
        return ;
    }

    if (item.quality < 50 && item.quality >= 1)
        item.quality = item.quality - 1;
        
    if (item.sellIn >= 0)
        item.sellIn = item.sellIn - 1;


}

void updateConjured(Item &item)
{
    if (item.sellIn < 0 && item.quality >= 4) {
        item.quality = item.quality - 4;
        return ;
    }

    if (item.quality < 50 && item.quality >= 2)
        item.quality = item.quality - 2;
        
    if (item.sellIn >= 0) {
        item.sellIn = item.sellIn - 1;
    }   
}

void updateSulfuras(Item &item)
{
    if (item.sellIn >= 1)
        item.sellIn = item.sellIn - 1;
}

void updateAgedBrie(Item &item)
{

    if (item.sellIn < 0 && item.quality < 49) {
        item.quality = item.quality + 2;
        return ;
    }
    if (item.quality < 50 && item.quality)
        item.quality = item.quality + 1;

    if (item.sellIn >= 1)
        item.sellIn = item.sellIn - 1;

}

int BackstageQulity(int sellin)
{
    if (sellin <= 5)
        return 3;
    else if (sellin <= 10)
        return 2;
    else
        return 1;

}

void updateBackstage(Item &item)
{
    if (item.sellIn <= 1) {
        item.quality = 0;
        item.sellIn  = item.sellIn - 1;
        return ;
    }


    if (item.quality < 50 && item.quality)
        item.quality = item.quality + BackstageQulity(item.sellIn);

    item.sellIn = item.sellIn - 1;
}
bool isBackstage(string name)
{
    if (name == "Backstage passes to a TAFKAL80ETC concert")
        return true;

    return false;
}

void GildedRose::updateQuality() 
{
    for (auto &item : items)
    {
        if (isAgedBrie(item.name))
            updateAgedBrie(item);
        else if (isBackstage(item.name))
            updateBackstage(item);
        else if (isConjured(item.name))
            updateConjured(item);
        else if (isSulfuras(item.name))
            updateSulfuras(item);
        else
            updateGeneral(item); 
    }
}
