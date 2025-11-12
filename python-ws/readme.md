# GRPC python implementation

This is a minimal client code that fetches on all rpc endpoint of the protobuff.

## To install dependency
- uv sync

## To run
- uv run python-ws/main.py

## Generate proto code
1. Regenerate the Python stubs so the sample client stays in sync:
	```bash
	cd python-ws/src
	uv run python -m grpc_tools.protoc \
	  -I ../../proto \
	  --python_out=. \
	  --grpc_python_out=. \
	  --pyi_out=. \
	  ../../proto/icd.proto
	```
2. Rerun the Python client: `uv run python-ws/main.py` or `cd python-ws && uv run main.py`
