// IO
// ==

static Term io_stdout_run(Env e, Term* f, int nl) {
  uint64_t n = 0;
  char* text = io_cstr(e, f[0], &n);
  io_out(stdout, text, n);
  if (nl) {
    io_out(stdout, "\n", 1);
  }
  free(text);
  return term_pak(CID_UNIT, 0);
}

#ifdef CID_IO_WRITE
Term io_write_run(Env e, Term* f, IoWork* w) {
  return io_stdout_run(e, f, 0);
}

static void __attribute__((constructor)) io_write_use(void) {
  io_eff(CID_IO_WRITE, io_write_run, 0);
}
#endif

#ifdef CID_IO_PRINT
Term io_print_run(Env e, Term* f, IoWork* w) {
  return io_stdout_run(e, f, 1);
}

static void __attribute__((constructor)) io_print_use(void) {
  io_eff(CID_IO_PRINT, io_print_run, 0);
}
#endif
