#ifndef LCD_H
#define LCD_H

void lcd_init(void);
void lcd_clear(void);     // Erase everything from screen
void lcd_print(char c);   // Write a character
void lcd_set_cursor(int); // Move the cursor around the screen matrix

#endif