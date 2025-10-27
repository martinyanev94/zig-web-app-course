// c_lib.c
#include <stdio.h>

void greet() {
    printf("Hello from C!\n");
}
const std = @import("std");
const c = @cImport({
    @cInclude("c_lib.c");
});

pub fn main() void {
    c.greet();
}
