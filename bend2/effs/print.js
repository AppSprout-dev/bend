// IO
// ==

function io_write(text) {
  io_out(1, io_bytes(text));
  return { $: "Unit" };
}

function io_print(text) {
  io_out(1, io_bytes(text + "\n"));
  return { $: "Unit" };
}

function io_print_err(text) {
  io_out(2, io_bytes(text + "\n"));
  return { $: "Unit" };
}
