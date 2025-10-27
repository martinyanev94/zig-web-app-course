// example.c
#include <stdio.h>

void greet() {
    printf("Greetings from C!\n");
}
const std = @import("std");
extern "c" fn greet();

pub fn main() void {
    greet();
}
