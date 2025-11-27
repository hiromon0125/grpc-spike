from google.protobuf import empty_pb2 as _empty_pb2
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from collections.abc import Mapping as _Mapping
from typing import ClassVar as _ClassVar, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class CommandResult(_message.Message):
    __slots__ = ()
    RETURN_CODE_FIELD_NUMBER: _ClassVar[int]
    return_code: int
    def __init__(self, return_code: _Optional[int] = ...) -> None: ...

class HandshakeRequest(_message.Message):
    __slots__ = ()
    OPERATOR_ID_FIELD_NUMBER: _ClassVar[int]
    operator_id: int
    def __init__(self, operator_id: _Optional[int] = ...) -> None: ...

class HandshakeResponse(_message.Message):
    __slots__ = ()
    STATUS_FIELD_NUMBER: _ClassVar[int]
    MAJOR_VERSION_FIELD_NUMBER: _ClassVar[int]
    MINOR_VERSION_FIELD_NUMBER: _ClassVar[int]
    status: CommandResult
    major_version: int
    minor_version: int
    def __init__(self, status: _Optional[_Union[CommandResult, _Mapping]] = ..., major_version: _Optional[int] = ..., minor_version: _Optional[int] = ...) -> None: ...

class PolarPanDiscreteRequest(_message.Message):
    __slots__ = ()
    DELTA_AZIMUTH_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    DELTA_ALTITUDE_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    DELAY_MS_FIELD_NUMBER: _ClassVar[int]
    EXECUTION_TIME_MS_FIELD_NUMBER: _ClassVar[int]
    delta_azimuth_tenths_deg: int
    delta_altitude_tenths_deg: int
    delay_ms: int
    execution_time_ms: int
    def __init__(self, delta_azimuth_tenths_deg: _Optional[int] = ..., delta_altitude_tenths_deg: _Optional[int] = ..., delay_ms: _Optional[int] = ..., execution_time_ms: _Optional[int] = ...) -> None: ...

class HomeRequest(_message.Message):
    __slots__ = ()
    DELAY_MS_FIELD_NUMBER: _ClassVar[int]
    delay_ms: int
    def __init__(self, delay_ms: _Optional[int] = ...) -> None: ...

class PolarPanContinuousStartRequest(_message.Message):
    __slots__ = ()
    MOVING_AZIMUTH_FIELD_NUMBER: _ClassVar[int]
    MOVING_ALTITUDE_FIELD_NUMBER: _ClassVar[int]
    moving_azimuth: int
    moving_altitude: int
    def __init__(self, moving_azimuth: _Optional[int] = ..., moving_altitude: _Optional[int] = ...) -> None: ...

class CartesianMoveDiscreteRequest(_message.Message):
    __slots__ = ()
    DELTA_X_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    DELTA_Y_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    DELTA_Z_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    DELAY_MS_FIELD_NUMBER: _ClassVar[int]
    EXECUTION_TIME_MS_FIELD_NUMBER: _ClassVar[int]
    delta_x_tenths_mm: int
    delta_y_tenths_mm: int
    delta_z_tenths_mm: int
    delay_ms: int
    execution_time_ms: int
    def __init__(self, delta_x_tenths_mm: _Optional[int] = ..., delta_y_tenths_mm: _Optional[int] = ..., delta_z_tenths_mm: _Optional[int] = ..., delay_ms: _Optional[int] = ..., execution_time_ms: _Optional[int] = ...) -> None: ...

class CartesianMoveContinuousStartRequest(_message.Message):
    __slots__ = ()
    MOVING_X_FIELD_NUMBER: _ClassVar[int]
    MOVING_Y_FIELD_NUMBER: _ClassVar[int]
    MOVING_Z_FIELD_NUMBER: _ClassVar[int]
    moving_x: int
    moving_y: int
    moving_z: int
    def __init__(self, moving_x: _Optional[int] = ..., moving_y: _Optional[int] = ..., moving_z: _Optional[int] = ...) -> None: ...

class ExecuteHardwareOperationRequest(_message.Message):
    __slots__ = ()
    SUBCOMMAND_ID_FIELD_NUMBER: _ClassVar[int]
    PAYLOAD_FIELD_NUMBER: _ClassVar[int]
    subcommand_id: int
    payload: bytes
    def __init__(self, subcommand_id: _Optional[int] = ..., payload: _Optional[bytes] = ...) -> None: ...

class ExecuteHardwareOperationResponse(_message.Message):
    __slots__ = ()
    STATUS_FIELD_NUMBER: _ClassVar[int]
    SUBCOMMAND_ID_FIELD_NUMBER: _ClassVar[int]
    PAYLOAD_FIELD_NUMBER: _ClassVar[int]
    status: CommandResult
    subcommand_id: int
    payload: bytes
    def __init__(self, status: _Optional[_Union[CommandResult, _Mapping]] = ..., subcommand_id: _Optional[int] = ..., payload: _Optional[bytes] = ...) -> None: ...

class GetSpeedResponse(_message.Message):
    __slots__ = ()
    STATUS_FIELD_NUMBER: _ClassVar[int]
    SPEED_FIELD_NUMBER: _ClassVar[int]
    status: CommandResult
    speed: int
    def __init__(self, status: _Optional[_Union[CommandResult, _Mapping]] = ..., speed: _Optional[int] = ...) -> None: ...

class SetSpeedRequest(_message.Message):
    __slots__ = ()
    SPEED_FIELD_NUMBER: _ClassVar[int]
    speed: int
    def __init__(self, speed: _Optional[int] = ...) -> None: ...

class SavePositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    ANCHOR_FIELD_NUMBER: _ClassVar[int]
    PARENT_REFERENCE_FIELD_NUMBER: _ClassVar[int]
    name: str
    anchor: bool
    parent_reference: str
    def __init__(self, name: _Optional[str] = ..., anchor: _Optional[bool] = ..., parent_reference: _Optional[str] = ...) -> None: ...

class DeletePositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    name: str
    def __init__(self, name: _Optional[str] = ...) -> None: ...

class GoToPositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    name: str
    def __init__(self, name: _Optional[str] = ...) -> None: ...

class SetPolarPositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    DELTA_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    AZIMUTH_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    RADIUS_TENTHS_FIELD_NUMBER: _ClassVar[int]
    name: str
    delta_tenths_deg: int
    azimuth_tenths_deg: int
    radius_tenths: int
    def __init__(self, name: _Optional[str] = ..., delta_tenths_deg: _Optional[int] = ..., azimuth_tenths_deg: _Optional[int] = ..., radius_tenths: _Optional[int] = ...) -> None: ...

class GetPolarPositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    name: str
    def __init__(self, name: _Optional[str] = ...) -> None: ...

class GetPolarPositionResponse(_message.Message):
    __slots__ = ()
    STATUS_FIELD_NUMBER: _ClassVar[int]
    DELTA_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    AZIMUTH_TENTHS_DEG_FIELD_NUMBER: _ClassVar[int]
    RADIUS_TENTHS_FIELD_NUMBER: _ClassVar[int]
    status: CommandResult
    delta_tenths_deg: int
    azimuth_tenths_deg: int
    radius_tenths: int
    def __init__(self, status: _Optional[_Union[CommandResult, _Mapping]] = ..., delta_tenths_deg: _Optional[int] = ..., azimuth_tenths_deg: _Optional[int] = ..., radius_tenths: _Optional[int] = ...) -> None: ...

class SetCartesianPositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    X_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    Y_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    Z_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    name: str
    x_tenths_mm: int
    y_tenths_mm: int
    z_tenths_mm: int
    def __init__(self, name: _Optional[str] = ..., x_tenths_mm: _Optional[int] = ..., y_tenths_mm: _Optional[int] = ..., z_tenths_mm: _Optional[int] = ...) -> None: ...

class GetCartesianPositionRequest(_message.Message):
    __slots__ = ()
    NAME_FIELD_NUMBER: _ClassVar[int]
    name: str
    def __init__(self, name: _Optional[str] = ...) -> None: ...

class GetCartesianPositionResponse(_message.Message):
    __slots__ = ()
    STATUS_FIELD_NUMBER: _ClassVar[int]
    X_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    Y_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    Z_TENTHS_MM_FIELD_NUMBER: _ClassVar[int]
    status: CommandResult
    x_tenths_mm: int
    y_tenths_mm: int
    z_tenths_mm: int
    def __init__(self, status: _Optional[_Union[CommandResult, _Mapping]] = ..., x_tenths_mm: _Optional[int] = ..., y_tenths_mm: _Optional[int] = ..., z_tenths_mm: _Optional[int] = ...) -> None: ...
