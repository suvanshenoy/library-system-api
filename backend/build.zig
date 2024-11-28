const std = @import("std");

pub fn build(b: *std.Build) !void {
    const build_cmake_cmd = b.addSystemCommand(&.{"cmake"});
    const build_dir = "build";

    build_cmake_cmd.addArgs(&.{
        "-GNinja",
        ".",
        "-B",
        build_dir,
    });

    const build_ninja_cmd = b.addSystemCommand(&.{"ninja"});

    build_ninja_cmd.addArgs(&.{
        "-C",
        build_dir,
    });

    var run_step = b.step("run-cmake", "This command will build using cmake");
    run_step.dependOn(&build_cmake_cmd.step);

    run_step = b.step("run-ninja", "This command will build using ninja");
    run_step.dependOn(&build_ninja_cmd.step);
}
