int square(int x) {
    return x * x;
}
const std = @import("std");

extern fn square(x: i32) i32;

pub fn main() void {
    const result = square(6);
    std.debug.print("The square is {}\n", .{result});
}
