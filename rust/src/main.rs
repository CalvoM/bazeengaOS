#![no_std]
#![no_main]
#![feature(custom_test_frameworks)]
#![test_runner(bazeenga_os::test_runner)]
#![reexport_test_harness_main = "test_main"]

use bazeenga_os::println;
use core::panic::PanicInfo;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    println!("Hello there");

    #[cfg(test)]
    test_main();
    // panic!("Test");
    loop {}
}

#[cfg(not(test))]
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("{}", info);
    loop {}
}

#[cfg(test)]
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    bazeenga_os::test_panic_handler(info)
}
