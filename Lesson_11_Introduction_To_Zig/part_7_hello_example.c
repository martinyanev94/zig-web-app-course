// example.c
#include <stdio.h>

void hello() {
    printf("Hello from C!\n");
}
const std = @import("std");
extern "c" fn hello();

pub fn main() void {
    hello();
}
