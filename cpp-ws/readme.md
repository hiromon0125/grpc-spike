# gRPC C++ implementation

This is a simple C++ gRPC server that logs every TalosOperator request and returns placeholder responses.

## Build
- Open the workspace in the dev container.
- Configure once: `cmake -S cpp-ws -B build`
- Incremental builds: `cmake --build build`

## Run
- Execute `./build/talos`

## Updating generated protobuf code
1. Edit `proto/icd.proto` with the new message or service changes.
2. Rebuild the C++ target: `cmake --build build` regenerates the C++ stubs in `build/generated` automatically.
3. Regenerate the Python stubs so the sample client stays in sync:
	```bash
	cd python-ws/src
	python -m grpc_tools.protoc \
	  -I ../../proto \
	  --python_out=. \
	  --grpc_python_out=. \
	  --pyi_out=. \
	  ../../proto/icd.proto
	```
4. Update `python-ws/src/icd_pb2_grpc.py` so the first protobuf import remains package-relative:
	```python
	from . import icd_pb2
	```
	(the generator rewrites this line to `import icd_pb2`; adjust it so `python-ws` keeps working as a package.)
5. Rerun the Python client: `python python-ws/main.py`

