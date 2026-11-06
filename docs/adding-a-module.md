# Adding a Module to AARUESP
## MADE BY AARUTO

1. Add a row to `registry/modules.csv` with id, name, category, bus, api_function, unit, board_min, dependency, example, status=IMPLEMENTED, description.
2. If a new API function is needed, add it to `src/AARUESP.h` and implement in `src/AARUESP.cpp`.
3. For a new driver, create `src/drivers/AaruX.h` (self-contained class, no globals).
4. Validate pins via `aaruespValidateDigitalPin()`/`aaruespValidateAnalogPin()`/`aaruespValidatePwmPin()`.
5. Guard third-party includes with `#if __has_include(<Lib.h>)`; return `AARUESP_MISSING_DEP` when absent.
6. Guard board-specific code with `AARUESP_BOARD_*` macros; return `AARUESP_UNSUPPORTED` otherwise.
7. Put pure math in `src/utility/AaruespMath.h` and extend `tests/host/test_aaruesp.py`.
8. Add an example under `examples/` using real API + valid per-board pins.
9. Run: `python tools/generate_registry.py`, `python tools/validate_registry.py`, `python tools/gen_keywords.py`, `python tools/gen_module_docs.py`, `python tests/validate/validate.py`, `python tests/host/test_aaruesp.py`.
10. All checks must pass before committing.
